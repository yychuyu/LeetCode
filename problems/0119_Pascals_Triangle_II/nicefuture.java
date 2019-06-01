import java.util.*;

class Solution {
    public List<Integer> getRow(int rowIndex) {    
        Vector outer =  new Vector();
        Vector init = new Vector();
        init.add(1);
        outer.add(init);
        
        if (rowIndex == 0) return init;
        
        Vector inner = new Vector();
        for (int i=1; i<=rowIndex; i++) {
            Vector last = (Vector) outer.lastElement();
            inner = new Vector();
            inner.add(1);
            for (int j=0; j+1<last.size(); j++) {
                inner.add((int)last.get(j)+(int)last.get(j+1));
            }
            inner.add(1);
            outer.add(inner);
        }
        
        return inner;
    }
}
