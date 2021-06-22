class Node {
    constructor(key, val, parent) {
        this.val = val;
        this.key = key;
        parent && this.attchParent(parent)
    }
    setChild(child) {
        this.next = child;
        child.prev = this;
    }
    attchParent(parent) {
        parent.next = this;
        this.prev = parent;
    }
}
class LRUCache {
    constructor(capacity) {
        this.capacity = capacity;
        this.headNode = new Node('', 0);
        this.tailNode = new Node('', 0, this.headNode);
        this.map = new Map();
    }
    delete(key) {
        let node = this.map.get(key);
        if (!node) return;
        node.prev.setChild(node.next);
        this.map.delete(key);
    }
    attachHead(key, value) {
        const node = new Node(key, value);
        node.setChild(this.headNode.next);
        this.headNode.setChild(node);
        this.map.set(key, node);
    }
    get(key) {
        const node = this.map.get(key);
        if (!node) return -1;
        this.delete(key);
        this.attachHead(key, node.val);
        return this.headNode.next.val;
    }
    put(key, value) {
        if (this.map.get(key)||this.map.size >= this.capacity) {
            this.delete(this.tailNode.prev.key);
        }
        this.attachHead(key, value);
    }
}