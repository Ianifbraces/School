#https://leetcode.com/problems/second-highest-salary/description/
#Difficulty: medium
import pandas as pd

def second_highest_salary(employee: pd.DataFrame) -> pd.DataFrame:
    N = 2
    employee.drop_duplicates('salary', inplace = True)
    employee = employee.sort_values(by = 'salary', ascending = False)
    if employee.shape[0] < N or N <= 0:
        return pd.DataFrame([[None]],columns = ['SecondHighestSalary'])
    return pd.DataFrame([[employee.iloc[N-1]['salary']]],columns = ['SecondHighestSalary'])