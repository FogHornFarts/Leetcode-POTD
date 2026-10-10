class Solution {
    public boolean lemonadeChange(int[] bills) {
        int note_5=0;        
        int note_10=0;        
        int note_20=0;
        boolean a=true;
        for(int i=0;i<bills.length;i++){
            if(bills[i]==5){
                note_5++;
            }
            if(bills[i]==10){
                if(note_5>0){
                    note_5--;
                    note_10++;
                }
                else a=false;
            }
            if(bills[i]==20){
                if(note_5>0 && note_10>0){
                    note_5--;
                    note_10--;
                    note_20++;
                }
                else if(note_5>2){
                    note_5-=3;
                    note_20++;
                }
                else a=false;
            }
        }
        return a;

    }
}