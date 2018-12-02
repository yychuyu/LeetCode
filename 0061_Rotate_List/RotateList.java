class Solution {
        public ListNode rotateRight(ListNode head, int k) {
//            检查链表
            if(head == null || head.next == null){
                return head;
            }
//            检查k
            if("".equals(k+"") || k<0){
                return head;
            }
//            统计链表长度
            ArrayList<ListNode> list = new ArrayList<>();
            ListNode tmp = head;
            while(true){
                list.add(tmp);
                if(tmp.next != null){
                    tmp = tmp.next;
                    continue;
                }
                break;
            }

//            检查k，
            int length = list.size();
            ListNode result = null;//存放结果
            ListNode pointer = new ListNode(0);//做指针
            ListNode mid = null;
            if( k < 0){
//                左移
                if( (k = Math.abs(k)) > length ){
                    k = k % length;
                }

            }else if ( k > 0){
//                右移
                if ( k > length ){
                    k = k % length;
                }
                if( k == 0){
                    return head;
                }
                for( int i=(length - k); i<length; i++){
                    if(result == null){
                        result = list.get(i);
                        pointer.next = list.get(i);
                    }else{
                        if(mid == null){
                            mid = list.get(i);
                            result.next = mid;
                            pointer.next = mid;
                        }else{
                            ListNode tmp2 = list.get(i);
                            mid.next = tmp2;
                            mid = tmp2;
                            pointer.next = tmp2;
                        }
                    }
                }
                for( int i=0; i<(length - k); i++){
                   if(mid == null){
                        mid = list.get(i);
                        result.next = mid;
                        pointer.next = mid;
                       if( i == (length - k - 1)){
                            mid.next = null;
                        }
                    }else{
                        ListNode tmp2 = list.get(i);
                        mid.next = tmp2;
                        mid = tmp2;
                        pointer.next = tmp2;
                        if( i == (length - k - 1)){
                            tmp2.next = null;
                        }
                    }
                }
            }else{
//                位置不变
                return head;
            }
//            测试能不能放进list里会不会有问题
//            for(ListNode node : list){
//                System.out.println(node.val);
//            }
            return result;
        }
    }