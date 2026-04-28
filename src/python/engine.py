# This file is the orchestrator for PyroCore
# It loads the CSV, calls the C++ stats functions, and prints the results

import sys
import os

# add the build/Release folder to Pythons path so it can find the compiled pyrocore module
# __file__ is the path to this file, so we navigate up two levels then into build/Release
sys.path.append(os.path.join(os.path.dirname(__file__), '..', '..', 'build', 'Release'))

# import our compiled C++ module
import pyrocore

# import the CSV loader we wrote in loader.py
from loader import load_csv

# import the visualizer for charts
from visualizer import plot_histograms, plot_means


def run(filepath):
    # load the CSV and unpack the data and column names
    data, columns = load_csv(filepath)

    # print a header for the results table
    print(f"\nPyroCore Results — {filepath}")
    print("-" * 60)
    print(f"{'Column':<20} {'Mean':>8} {'Median':>8} {'Std Dev':>8} {'Min':>8} {'Max':>8}")
    print("-" * 60)

    # collect means so we can pass them to the bar chart later
    means = []

    # loop through each column by index and name
    for i, col in enumerate(columns):
        # extract all values for this column by grabbing index i from every row
        column_values = [row[i] for row in data]

        # call the C++ functions for each stat
        mean    = pyrocore.compute_mean(column_values)
        median  = pyrocore.compute_median(column_values)
        std_dev = pyrocore.compute_std_dev(column_values)
        minimum = pyrocore.compute_min(column_values)
        maximum = pyrocore.compute_max(column_values)

        # save the mean so the bar chart can use it
        means.append(mean)

        # print one row of results formatted to 2 decimal places
        print(f"{col:<20} {mean:>8.2f} {median:>8.2f} {std_dev:>8.2f} {minimum:>8.2f} {maximum:>8.2f}")

    print("-" * 60)

    # generate the histogram for each column
    plot_histograms(data, columns)

    # generate the bar chart comparing mean values
    plot_means(columns, means)


# only run this if the file is executed directly (not imported by another file)
if __name__ == "__main__":
    # expect the CSV path as a command line argument
    if len(sys.argv) < 2:
        print("Usage: python engine.py <path to CSV>")
        sys.exit(1)

    run(sys.argv[1])
