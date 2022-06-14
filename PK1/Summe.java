
public class Summe
{

    public static int intervall(int a, int b){
        int sum = 0;
        if(a>b){
            int temp = b;
            b=a;
            a=temp;
        }

        for(; a<=b; a++){
            sum = sum+a; 
        }
        return sum;
    }

    public static int digitSum(int x){
        if(x<0){
            x=x*(-1);
        }
        int querSumme = 0;
        while(x!=0){
            querSumme += x%10;
            x/=10;  // x=x/10
        }
        return querSumme;
    }

    public static String digitToString(int z1) {
        if(z1<=9 && z1>=0){
            if(z1 == 0){
                return "NULL";
            }
            if(z1 ==1){
                return "EINS";
            }
            if(z1 == 2){
                return "ZWEI";
            }
            if(z1 == 3){
                return "DREI";
            }
            if(z1 == 4){
                return "VIER";
            }
            if(z1 == 5){
                return "FÜNF";
            }
            if(z1 ==6){
                return "SECHS";
            }
            if(z1 == 7){
                return "SIEBEN";
            }
            if(z1 == 8){
                return "ACHT";
            }
            if(z1 == 9){
                return "NEUN";
            }    
        }
        return "";    
    }

    public static String intToString(int z){
        String string="";
        boolean zN=false;
        if(z<0){
            z=z*(-1);
            zN = true;
        } 
            
        while(z!=0){    
            int temp = z%10;
            z=z/10;
            if(string != ""){
                string = digitToString(temp) + "-" + string;
            }
            else{
                 string = digitToString(temp) + string;
                }
        }
        if(zN){
            string = "minus"+"-"+ string;
        }

        return string;
    }
    
    public static String digitSumToString(int x){
        return
        intToString(digitSum(x));
        
    }
     
    public static boolean isHarshad(int z){
        return z%digitSum(z) == 0;    
        }
        
    public static void computeHarshads(int n){
        for(int i=1; i<=n;i++){
            if(isHarshad(i)){
                System.out.print("Harshads: "+ i +"\n");
            }    
        } 
    }
    
    public static double computeEuler(int n){
        double e = 0;
        int tempFak = 1;
        int k = 0;
        while(k<=n){
            e+=1.0/tempFak;
            k++;
            tempFak *= k;
    }
        return e;
    }
    
}