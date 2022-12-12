#ifndef SCORES_H
#define SCORES_H

#include <vector>

class HighScores
{
public:
    HighScores(const int &score);
    void LoadScoresFile(std::string fname);
    void WriteNewScoresFile(std::string fname);
    bool CheckHighScore(const int score);
    std::vector<int> GetHighScores();
    std::vector<std::string> GetHighScoreNames();
    bool set_high_score;
    void AddHighScore(const int score,std::string name_to_add);
    void WriteScoresToFile(std::string fname);
private:
    std::string current_name_;
    std::vector<int> high_scores_;
    std::vector<std::string> names_;
};

#endif