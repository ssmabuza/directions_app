

#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>


std::ostream&
operator<<(std::ostream&,const std::vector<std::pair<std::string,std::string>>&);


int main()
{
  std::vector<std::pair<std::string,std::string>> vec_to_sort;
  auto comp = [](std::pair<std::string,std::string> p1, std::pair<std::string,std::string> p2)->bool
         { if (p1.first < p2.first) return true;
           else if (p1.first == p2.first) return p1.second < p2.second;
           else return false; };
  
  vec_to_sort.push_back(std::make_pair("nigeria","lagos"));
  vec_to_sort.push_back(std::make_pair("southafrica","capetown"));
  vec_to_sort.push_back(std::make_pair("nigeria","abuja"));
  vec_to_sort.push_back(std::make_pair("ghana","kumasi"));
  vec_to_sort.push_back(std::make_pair("egypt","cairo"));
  vec_to_sort.push_back(std::make_pair("southafrica","durban"));
  vec_to_sort.push_back(std::make_pair("ghana","accra"));
  vec_to_sort.push_back(std::make_pair("southafrica","joburg"));
  vec_to_sort.push_back(std::make_pair("southafrica","durbanville"));
  vec_to_sort.push_back(std::make_pair("kenya","mumbasi"));
  vec_to_sort.push_back(std::make_pair("egypt","alexandra"));
  vec_to_sort.push_back(std::make_pair("sudan","kartoum"));
  
  std::cout << "unsorted country: city list" << std::endl;
  std::cout << vec_to_sort << std::endl << std::endl;
  std::sort(vec_to_sort.begin(),vec_to_sort.end(),comp);
  std::cout << "sorted country: city list" << std::endl;
  std::cout << vec_to_sort << std::endl << std::endl;
  
  return 0;
}


std::ostream&
operator<<(std::ostream& ofs,const std::vector<std::pair<std::string,std::string>>& vec)
{
  for (const auto& it : vec)
  {
    ofs << it.first << ": " << it.second << std::endl;
  }
  return ofs;
}
