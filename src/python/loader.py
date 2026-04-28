import pandas as pd

def load_csv(filepath):
    # read the CSV file into a pandas DataFrame
    df = pd.read_csv(filepath)

    # drop any non-numeric columns like names or labels so C++ only gets numbers
    numeric_df = df.select_dtypes(include='number')

    # convert the DataFrame to a plain Python list of lists so C++ can read it
    data = numeric_df.values.tolist()

    # grab the column names so we can label results later
    columns = numeric_df.columns.tolist()

    return data, columns
