#ifndef SPAMCLASSIFIER_H
#define SPAMCLASSIFIER_H

#include <dlib/svm.h>
#include <string>
#include <vector>
#include <map>


struct ClassificationMetrics {
    double accuracy;
    double precision;
    double recall;
    double f1_score;
};


class SpamClassifier {
private:
    typedef dlib::matrix<double, 10, 1> sample_type;
    typedef dlib::radial_basis_kernel<sample_type> kernel_type;
    
    std::vector<std::string> vocabulary;
    dlib::svm_c_trainer<kernel_type> trainer;
    dlib::decision_function<kernel_type> model;
    bool isTrained;

    sample_type extractFeatures(const std::string& message);

public:
    SpamClassifier();
    void train(const std::vector<std::pair<std::string, int>>& trainingData);
    int predict(const std::string& message);
    ClassificationMetrics evaluate(const std::vector<std::pair<std::string, int>>& testData);
};

#endif