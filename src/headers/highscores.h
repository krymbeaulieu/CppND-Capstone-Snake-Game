#ifndef SCORES_H
#define SCORES_H

#include <vector>

class HighScores
{
public:
    HighScores(const int &score);
    void LoadScoresFile(std::string fname);
    void WriteNewScoresFile(std::string fname);
    // void SetHighScoreStatus(const int &score);
    bool CheckSetHighScore(const int &score);

    bool set_high_score;
    void AddHighScore(const int score, std::string name_to_add);
    void WriteScoresToFile(std::string fname);
    std::vector<int> GetHighScores();
    std::vector<std::string> GetHighScoreNames();
    // bool GetSetHighScoreStatus();
    // bool set_high_score_;

private:
    std::string current_name_;
    std::vector<int> high_scores_;
    std::vector<std::string> names_;
};

#endif