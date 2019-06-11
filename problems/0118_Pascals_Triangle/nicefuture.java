import java.util.*;

class Solution {
    public List<List<Integer>> generate(int numRows) {
        
        if (numRows < 1) return new Vector();
        
        Vector outer =  new Vector();
        Vector init = new Vector();
        init.add(1);
        outer.add(init);
        
        for (int i=1; i<numRows; i++) {
            Vector last = (Vector) outer.lastElement();
            Vector inner = new Vector();
            inner.add(1);
            for (int j=0; j+1<last.size(); j++) {
                inner.add((int)last.get(j)+(int)last.get(j+1));
            }
            inner.add(1);
            outer.add(inner);
        }
        
        return outer;
    }
}
