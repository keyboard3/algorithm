//采用嵌套数组，递归展开
var ThroneInheritance = function (kingName) {
  this.array = [kingName];
  this.map = new Map([[kingName, this.array]]);
};

ThroneInheritance.prototype.birth = function (parentName, childName) {
  const parentList = this.map.get(parentName);
  const list = [childName];
  parentList.push(list);
  this.map.set(childName, list);
};

ThroneInheritance.prototype.death = function (name) {
  const list = this.map.get(name);
  delete list[0];
};

ThroneInheritance.prototype.getInheritanceOrder = function () {
  return this.array.flat(Infinity);
};