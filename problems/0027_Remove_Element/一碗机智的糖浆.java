class Solution {
    public int removeElement(int[] nums, int val) {
        //�͵�ɾ������ֵ������Ԫ��
        // O(1) �Ķ���ռ�������
        int i=0;
        for(int j=0;j<nums.length;j++){
            if(nums[j]!=val){//ֻҪ��ֵ������val�Ͱ�ֵ����nums[i]���µ�����O��1������Ŀռ�
                nums[i]=nums[j];
                i++;
            }
        }
        //���������鳤��
        return i;
    }
}