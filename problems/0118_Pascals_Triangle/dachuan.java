public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> list = new ArrayList<>();
        List<Integer> item;//当前行的集合
        List<Integer> last = null; //上一行的集合
        int index = 1; //行号，每行元素个数和行号一致
        while (index <= numRows) {
            item = new ArrayList<>();
            //循环index次，向item中添加元素
            a:
            for (int i = 0; i < index; i++) {
                if(last == null){
                    item.add(1);
                    break a;
                }else if(i == 0){
                    item.add(1);
                }else if(i == index - 1){
                    item.add(last.get(i - 1));
                }else{
                    item.add(last.get(i - 1) + last.get(i));
                }
            }
            last = item;
            list.add(item);
            index++;
        }
        return list;
    }