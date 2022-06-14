

public class Time
{
    public static void main (String[] args){
      System.out.println("Zeit in Sekunden:" + toSeconds(1,1));
    }
    
    
    public static int toSeconds( int hours, int minutes){
        return hours*3600+minutes*60;
    }
    
    public static String showTime(int sek){
    String zeit = sek/60 +":"+sek%60;
    
    return zeit;
    
    }
    
}
    // Instanzvariablen - ersetzen Sie das folgende Beispiel mit Ihren Variablen
    