#https://leetcode.com/problems/delete-duplicate-emails/description/
# Difficulty: easy
import pandas as pd

def delete_duplicate_emails(person: pd.DataFrame) -> None:
    # Assuming 'Person' is the DataFrame containing the data
    person.sort_values('id', inplace=True)  # Ensure that the smallest id appears first
    person.drop_duplicates(subset='email', keep='first', inplace=True)