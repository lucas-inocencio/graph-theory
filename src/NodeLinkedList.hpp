class NodeLinkedList
{
public:
    int id_;
    int capacity_;
    int allocation_flow_;
    bool is_reverse_;
    NodeLinkedList *next_;

    NodeLinkedList() : id_{0}, capacity_{0}, allocation_flow_{0}, is_reverse_{false}, next_{nullptr} {}
    NodeLinkedList(int id, int capacity) : id_{id}, capacity_{capacity}, allocation_flow_{0}, is_reverse_{false}, next_{nullptr} {}
    NodeLinkedList(int id, int capacity, bool is_reverse) : id_{id}, capacity_{capacity}, allocation_flow_{0}, is_reverse_{is_reverse}, next_{nullptr} {}

    int id() const { return id_; }
    int capacity() const { return capacity_; }
    int allocation_flow() const { return allocation_flow_; }
    bool is_reverse() const { return is_reverse_; }
    NodeLinkedList *next() const { return next_; }

    void set_id(int id) { id_ = id; }
    void set_capacity(int capacity) { capacity_ = capacity; }
    void set_allocation_flow(int allocation_flow) { allocation_flow_ = allocation_flow; }
    void set_is_reverse(bool is_reverse) { is_reverse_ = is_reverse; }
    void set_next(NodeLinkedList *next) { next_ = next; }
};
