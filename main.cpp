#include "SpamClassifier.h"
#include "DataLoader.h"
#include <iostream>
#include <filesystem>
#include <iomanip>


void printMetrics(const ClassificationMetrics& metrics) {
    std::cout << std::fixed << std::setprecision(4);
    std::cout << "Classification Metrics:" << std::endl;
    std::cout << "Accuracy:  " << metrics.accuracy << std::endl;
    std::cout << "Precision: " << metrics.precision << std::endl;
    std::cout << "Recall:    " << metrics.recall << std::endl;
    std::cout << "F1 Score:  " << metrics.f1_score << std::endl;
}

int main() {
    try {

        std::string trainFile = "C:/Users/user/CLionProjects/CodeForTest1withC/train_data.csv";
        std::string testFile = "C:/Users/user/CLionProjects/CodeForTest1withC/test_data.csv";

        std::cout << "Checking files:" << std::endl;
        std::cout << "Train file path: " << trainFile << std::endl;
        std::cout << "Test file path: " << testFile << std::endl;
        std::cout << "Train file exists: " << std::filesystem::exists(trainFile) << std::endl;
        std::cout << "Test file exists: " << std::filesystem::exists(testFile) << std::endl;

        if (!std::filesystem::exists(trainFile) || !std::filesystem::exists(testFile)) {
            throw std::runtime_error("Training or test data files not found");
        }

        auto trainingData = DataLoader::loadFromCSV(trainFile);
        auto testData = DataLoader::loadFromCSV(testFile);

        SpamClassifier classifier;
        classifier.train(trainingData);

        auto metrics = classifier.evaluate(testData);
        printMetrics(metrics);

        std::string testMsg = "Click now to get free money";
        int prediction = classifier.predict(testMsg);
        std::cout << "\nTest Message: \"" << testMsg << "\"\n";
        std::cout << "Prediction: " << (prediction > 0 ? "SPAM" : "NOT SPAM") << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
