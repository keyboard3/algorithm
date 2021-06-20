#include "string"
#include "vector"
#include "unordered_map"
#include "unordered_set"
using namespace std;

class ThroneInheritance
{
public:
  unordered_map<string, vector<string>> nameChildMap;
  unordered_map<string, bool> deadMap;
  ThroneInheritance(string kingName)
  {
    nameChildMap["root"].push_back(kingName);
  }

  void birth(string parentName, string childName)
  {
    nameChildMap[parentName].push_back(childName);
  }

  void death(string name)
  {
    deadMap[name] = true;
  }

  vector<string> getInheritanceOrder()
  {
    vector<string> orders;
    dfsOrder(orders, "root");
    return orders;
  }
  void dfsOrder(vector<string> &orders, string parentName)
  {
    for (auto child : nameChildMap[parentName])
    {
      if (!deadMap[child])
        orders.push_back(child);
      if (nameChildMap.find(child) != nameChildMap.end())
        dfsOrder(orders, child);
    }
  }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */