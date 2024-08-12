#https://leetcode.com/problems/rearrange-products-table/description/
#Difficulty: easy
import pandas as pd
import numpy as np
def rearrange_products_table(products: pd.DataFrame) -> pd.DataFrame:
    products_long = pd.melt(products, id_vars=['product_id'], value_vars=['store1', 'store2', 'store3'], 
                        var_name='store', value_name='price')
    # Remove rows where the price is null
    products_long = products_long.dropna(subset=['price'])

    # Optionally, reset the index   
    products_long.reset_index(drop=True, inplace=True)
    return products_long