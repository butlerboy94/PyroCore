# This file handles all the chart generation for PyroCore
# It takes the loaded data and computed stats and turns them into matplotlib charts

import matplotlib.pyplot as plt
import math


def plot_histograms(data, columns):
    # figure out how many rows of subplots we need (2 charts per row)
    num_cols = len(columns)
    num_rows = math.ceil(num_cols / 2)

    # create a figure with one subplot per column
    fig, axes = plt.subplots(num_rows, 2, figsize=(12, 4 * num_rows))
    fig.suptitle("PyroCore — Column Distributions", fontsize=14)

    # flatten the axes array so we can loop through it easily
    axes = axes.flatten()

    # loop through each column and draw its histogram
    for i, col in enumerate(columns):
        # extract all values for this column
        column_values = [row[i] for row in data]

        # draw the histogram on its subplot
        axes[i].hist(column_values, bins=10, color='steelblue', edgecolor='black')
        axes[i].set_title(col)
        axes[i].set_xlabel("Value")
        axes[i].set_ylabel("Frequency")

    # hide any unused subplots if we have an odd number of columns
    for j in range(num_cols, len(axes)):
        axes[j].set_visible(False)

    plt.tight_layout()
    plt.show()


def plot_means(columns, means):
    # create a bar chart comparing the mean value of each column
    plt.figure(figsize=(10, 5))
    plt.bar(columns, means, color='steelblue', edgecolor='black')
    plt.title("PyroCore — Mean Values by Column")
    plt.xlabel("Column")
    plt.ylabel("Mean Value")

    # add the exact value on top of each bar so its easy to read
    for i, val in enumerate(means):
        plt.text(i, val + (max(means) * 0.01), f"{val:.2f}", ha='center', fontsize=9)

    plt.tight_layout()
    plt.show()
