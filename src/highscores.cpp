#include <iostream>
#include <fstream>
#include "headers/defs.h"
#include "headers/highscores.h"

HighScores::HighScores(const int &score)
{
  LoadScoresFile(SCORE_FNAME); // load once!
  set_high_score = CheckHighScore(score);
}

//! check if score is within ranking
bool HighScores::CheckHighScore(const int score)
{
  if (score > high_scores_[high_scores_.size() - 1] || high_scores_.size() < MAX_HIGH_SCORES)
  {
    return true; //greater than last item (already sorted) or less than max high scores
  }
  return false;
}
//! load the scores file for the lose screen and writing a new high score
void HighScores::LoadScoresFile(std::string fname)
{
  int rank;
  std::string name;
  int loaded_score;

  std::string header;
  std::ifstream file(SCORE_FNAME);
  if (!file.is_open())
  { /* validate file open for reading */
    HighScores::WriteNewScoresFile(SCORE_FNAME);
    file.close();
  }
  else
  {
    //handle score loading
    file >> header >> header >> header; // ignore header
    while (file >> rank >> name >> loaded_score)
    {
      // std::cout << rank << name << loaded_score <<std::endl;
      names_.emplace_back(name);
      high_scores_.emplace_back(loaded_score);
    }
    file.close();
  }
}

//! wite a score file and handle score loading
void HighScores::WriteNewScoresFile(std::string fname)
{
  std::ofstream file(fname);
  file << SCORE_HEADERS;
}

std::vector<int> HighScores::GetHighScores()
{
  return high_scores_;
}
std::vector<std::string> HighScores::GetHighScoreNames()
{
  return names_;
}
//! add high score to the list (in the right spot)
void HighScores::AddHighScore(const int score,std::string name_input_text)
{
  std::cout << "GOT TO HIGH SCORE ADD" << std::endl;
  std::cout << "HIGH SCORES BEFORE: ";
  for (auto s : high_scores_)
  {
    std::cout << s << " ";
  }
  std::cout << std::endl;
  std::cout << "NAEMS SCORES BEFORE: ";
  for (auto s : names_)
  {
    std::cout << s << " ";
  }
  std::cout << std::endl;
    

  const size_t NUM_HIGH_SCORES = high_scores_.size();
  int new_max = (NUM_HIGH_SCORES<=MAX_HIGH_SCORES) ? (NUM_HIGH_SCORES+1) : NUM_HIGH_SCORES;
  std::vector<int> new_high_scores(new_max);
  std::vector<std::string> new_names(new_max);
  int i;
  for (i = 0; i < NUM_HIGH_SCORES; i++)
  {

    if (high_scores_[i] < score)
    {
      break;
    }
  }
  auto begin = std::begin(high_scores_);
  auto begin_n = std::begin(names_);
  std::copy(begin, std::next(begin, i), std::begin(new_high_scores));
  std::copy(begin_n, std::next(begin_n, i), std::begin(new_names));
std::cout << "NAEMS SCORES after left copy: ";
  for (auto s : new_names)
  {
    std::cout << s << " ";
  }
  std::cout << std::endl;
  
  new_high_scores[i] = score;
  new_names[i] = (name_input_text);
  std::cout << "NAEMS SCORES after item copy: ";
  for (auto s : new_names)
  {
    std::cout << s << " ";
  }
  std::cout << std::endl;
  std::copy(std::next(begin, i),std::end(high_scores_),std::next(std::begin(new_high_scores),i+1));
  std::copy(std::next(begin_n, i),std::end(names_),std::next(std::begin(new_names),i+1));
  std::cout << "NAEMS SCORES after right copy: ";
  for (auto s : new_names)
  {
    std::cout << s << " ";
  }
  std::cout << std::endl;

  // for (int j = i+1; j <= NUM_HIGH_SCORES + 1; j++)
  // {
  //   new_high_scores[j] = high_scores_[j-1];
  // }

  high_scores_ = new_high_scores;
  names_ = new_names;
  std::cout << "HIGH SCORES after: ";
  for (auto s : high_scores_)
  {
    std::cout << s << " ";
  }
  std::cout << std::endl;
  std::cout << "NAEMS SCORES after: ";
  for (auto s : new_names)
  {
    std::cout << s << " ";
  }
  std::cout << std::endl;

  WriteScoresToFile(SCORE_FNAME);

}

void HighScores::WriteScoresToFile(std::string fname){
   std::ofstream ofs(fname, std::ofstream::trunc);
   ofs << SCORE_HEADERS << std::endl;
    for(int i = 0; i < high_scores_.size();i++){
        ofs << i+1 << " " << names_[i] << " " << std::to_string(high_scores_[i]) << std::endl;
    }
   ofs.close();
}
