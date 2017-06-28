#ifndef PACBIOFLSCORES
#define PACBIOFLSCORES

#include<cstdlib>
#include<fstream>
#include<map>

class PacbioFlScores {
 private:
  std::map<std::string, double> pacbioFlScores;
 public:

  void loadScores(std::string path) {
    std::ifstream fin;
    std::string transcript_id;
    int fl;
    double fl_score;

    fin.open(path.c_str());
    if (!fin.is_open()) {
        std::cerr << "Cannot open " << path << std::endl;
        exit(-1);
    }
    
    pacbioFlScores.clear();
    while(true) {
      if ( !(fin >> transcript_id >> fl >> fl_score) ) break;
      pacbioFlScores.insert( std::make_pair(transcript_id, fl_score) );
    }
  }

  double getScore(std::string key) {
      std::map<std::string, double>::iterator it;
      it = pacbioFlScores.find(key);
      if ( it != pacbioFlScores.end() ) {
          return it->second;
      } else {
          return -1;
      }
  }

};

#endif
