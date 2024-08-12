#https://leetcode.com/problems/nth-highest-salary/description/
#Difficulty: medium
import pandas as pd

def nth_highest_salary(employee: pd.DataFrame, N: int) -> pd.DataFrame:
    employee.drop_duplicates('salary', inplace = True)
    employee = employee.sort_values(by = 'salary', ascending = False)
    if employee.shape[0] < N or N <= 0:
        return pd.DataFrame([[None]],columns = [f'getNthHighestSalary({N})'])
    return pd.DataFrame([[employee.iloc[N-1]['salary']]],columns = [f'getNthHighestSalary({N})'])