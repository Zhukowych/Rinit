#include <iostream>
#include "../../RequestHandler/Requests/Requests.hpp"


int main(){
  TrainReccomenderModels request(111, 111);
  request.Execute();
  return 0;
}
