//This file handles all the statistical computations for PyroCore
//It gets called by bindings.cpp which exposes these functions to Python

#include <cmath>      //needed for sqrt() in standard deviation
#include <vector>     //needed for std::vector which is how we pass lists of numbers
#include <algorithm>  //needed for std::sort() in the median function


//This function takes a list of numbers and returns their average
double compute_mean(const std::vector<double>& numbers) {
    //if the list is empty return 0 so we dont divide by zero
    if (numbers.empty()) {
        return 0.0;
    }

    double sum = 0.0;
    //loop through every number and add it to sum
    for (const auto& n : numbers) {
        sum += n;
    }
    //divide total by how many numbers there are to get the average
    return sum / numbers.size();
}

//This function sorts the list and returns the middle value
//takes a copy of the vector (no &) because we need to sort it without changing the original
double compute_median(std::vector<double> numbers) {
    //if the list is empty return 0 so we dont crash
    if (numbers.empty()) {
        return 0.0;
    }

    //sort the numbers from smallest to largest
    std::sort(numbers.begin(), numbers.end());
    size_t n = numbers.size();

    //if there are an even number of values average the two middle ones
    if (n % 2 == 0) {
        return (numbers[n / 2 - 1] + numbers[n / 2]) / 2.0;
    } else {
        //if odd just return the middle one
        return numbers[n / 2];
    }
}

//This function returns how spread out the numbers are from the mean
double compute_std_dev(const std::vector<double>& numbers) {
    //if the list is empty return 0 so we dont crash
    if (numbers.empty()) {
        return 0.0;
    }

    //get the mean first since we need it for the formula
    double mean = compute_mean(numbers);
    double sum_squared_diff = 0.0;

    //for each number calculate how far it is from the mean then square it
    for (const auto& n : numbers) {
        sum_squared_diff += (n - mean) * (n - mean);
    }

    //divide by count then take the square root to get standard deviation
    return sqrt(sum_squared_diff / numbers.size());
}

//This function finds the smallest value in the list
double compute_min(const std::vector<double>& numbers) {
    //if the list is empty return 0 so we dont crash
    if (numbers.empty()) {
        return 0.0;
    }

    //start by assuming the first number is the smallest
    double min_value = numbers[0];

    //loop through the rest and update if we find something smaller
    for (const auto& n : numbers) {
        if (n < min_value) {
            min_value = n;
        }
    }
    return min_value;
}

//This function finds the largest value in the list
double compute_max(const std::vector<double>& numbers) {
    //if the list is empty return 0 so we dont crash
    if (numbers.empty()) {
        return 0.0;
    }

    //start by assuming the first number is the largest
    double max_value = numbers[0];

    //loop through the rest and update if we find something larger
    for (const auto& n : numbers) {
        if (n > max_value) {
            max_value = n;
        }
    }
    return max_value;
}
