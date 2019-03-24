class RecentCounter {

    private LinkedList<Integer> linkedList;

    public RecentCounter() {
        linkedList = new LinkedList<>();
    }

    public int ping(int t) {
        linkedList.addLast(t);
        while (t - linkedList.getFirst() > 3000) {
            linkedList.removeFirst();
        }
        return linkedList.size();
    }
}

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter obj = new RecentCounter();
 * int param_1 = obj.ping(t);
 */