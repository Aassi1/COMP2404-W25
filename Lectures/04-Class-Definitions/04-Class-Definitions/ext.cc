#include <string>

using namespace std;

string name = "Billy the Kid";
//static string name = "Billy the Kid";

string manager = "Jesse James";

/*
 Unnamed namespace variables are global for this file only.
 Cannot be accessed by linking.
*/
namespace
{
  string manager = "Someone";
  string cashier = "William H. Bonney";
  string stock = "Pat Garrett";
}