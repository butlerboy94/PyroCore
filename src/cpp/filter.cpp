//This file handles row filtering for PyroCore
//It takes a 2D table of numbers and returns only the rows that pass a threshold check

#include <vector>  //needed for std::vector which is how we store the table and rows


//This function filters rows from a table based on a threshold value in a specified column
//table is the full dataset, column_index is which column to check, threshold is the cutoff value
std::vector<std::vector<double>> filter_rows(
    const std::vector<std::vector<double>>& table,
    size_t column_index,
    double threshold) {

    //this will hold the rows that pass the filter
    std::vector<std::vector<double>> filtered_rows;

    //loop through every row in the table
    for (const auto& row : table) {
        //first check that the row actually has the column we want to avoid a crash
        //then check if the value in that column is greater than our threshold
        if (row.size() > column_index && row[column_index] > threshold) {
            //if it passes add the whole row to our results
            filtered_rows.push_back(row);
        }
    }

    return filtered_rows;
}
