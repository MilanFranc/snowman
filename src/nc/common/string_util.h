//
// Created by Milan Franc on 05/03/2018.
//

#ifndef SNOWMAN_STRING_UTIL_H
#define SNOWMAN_STRING_UTIL_H

inline std::string str_tolower(std::string s) {
   std::transform(s.begin(), s.end(), s.begin(),
                  [](unsigned char c){ return std::tolower(c); } // correct
   );
   return s;
}

inline std::string str_toupper(std::string s) {
   std::transform(s.begin(), s.end(), s.begin(),
                  [](unsigned char c){ return std::toupper(c); } // correct
   );
   return s;
}

#endif //SNOWMAN_STRING_UTIL_H
