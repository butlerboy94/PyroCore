import pandas as pd

def load_csv(filepath):
    # read the CSV into a DataFrame
    # select only numeric columns
    # convert to a list of lists
    # return the data and column names

    df = pd.read_csv(filepath)
    numeric_df = df.select_dtypes(include='number')
    data = numeric_df.values.tolist()
    columns = numeric_df.columns.tolist()

    return data, columns
