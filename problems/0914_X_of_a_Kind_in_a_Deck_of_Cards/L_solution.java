import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

public class L_solution {

    public static boolean hasGroupsSizeX(int[] deck) {
        HashMap<Integer,Integer> map=new HashMap<>();
        for(int i=0;i<deck.length;i++){
            if(map.containsKey(deck[i])){
                map.put(deck[i],map.get(deck[i])+1);
            }
            else map.put(deck[i],1);
        }
        int[] a=new int[map.size()];
        int index=0;
        for(Map.Entry<Integer,Integer> entry:map.entrySet()){
            a[index]=entry.getValue();
            index++;
        }
        int min=1000;
        for(int i=0;i<a.length;i++){
            if(a[i]<min) min=a[i];
        }

        for(int i=2;i<=min;i++){
            int j=0;
            for(j=0;j<a.length;j++){
                if(a[j]%i!=0) break;
            }
            if(j==a.length) return true;
        }
        return false;
    }

    public static void main(String[] args){
        int[] deck=new int[]{1,1,1,2,2,2,2,2,3,3,3};
        System.out.println(hasGroupsSizeX(deck));
    }
}
