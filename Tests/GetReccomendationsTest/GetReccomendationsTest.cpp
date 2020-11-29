#include <iostream>
#include "../../RequestHandler/Requests/Requests.hpp"

int main(){
  GetReccomendationsRequest request(2074, 111);
  request.Execute();
  return 0;
}
