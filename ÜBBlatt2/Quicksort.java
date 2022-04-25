import java.util.Arrays;
import java.util.Scanner;
import java.util.ArrayList;

public class Quicksort {

public static void main (String [] args) {

        Scanner input = new Scanner (System.in);
        //Listen-Konstruktor wird mit Argument aufgerufen, da sonst mit Länge 10 initialisiert:
        ArrayList ints = new ArrayList<Integer>(0);
        while (input.hasNextLine()) {
            try {
            ints.add(Integer.parseInt (input.nextLine()));
            }
            catch (NumberFormatException e) {
            System.err.println("Input list contains a non-number.");
            return;
            }
        }
        //Array wird mit exakt benötigter Länge initialisiert:
        int [] output = new int[ints.size()];
        for (int i = 0; i< ints.size(); i++) {
            output[i] = (Integer)ints.get(i);
        }

        if (output.length == 0) { //Für sinnvolle Ausgaben muss mindestens ein Element im Array enthalten sein
            System.err.println("Input list is empty.");
            return;
        }
        if (output.length < 20) {
            System.out.println(Arrays.toString(output));
            qsort(output);
            System.out.println(Arrays.toString(output));
        }
        else {
            qsort(output);
        }

        double med; //Der Median ist möglicherweise keine Ganzzahl
        if (output.length % 2 == 1) {
            med = output[output.length / 2];
        }
        else {
            double sum1 = output[output.length / 2];
            double sum2 = output[output.length / 2 -1];
            med = (sum1 + sum2) /2;
        }
        System.out.println( "Min: "+ output[output.length-1] +", Med: "+ med +", Max: "+ output[0]);
    }


public static int partition (int[] data, int l, int r) {
        if (l>=r) { //Abbruchbedingung, höchstens ein Element enthalten
            return l;
        }
        int m = l; //Das erste Element des (Teil-)Arrays wird als Pivot genutzt
        // Die Variable l fungiert im Folgenden gewissermaßen als Zeiger auf das nächste zu vergleichende Element des (Teil-)Arrays
        l++;
        while (l<=r) { //Vergleiche aller anderen Elemente mit Pivot, bis rechte Arraygrenze erreicht ist
            if (data[l]>= data[m]) {
                int temp = data[l];
                for (int i = l; i > m; i--) {
                    data[i] = data[i-1];
                }
                data[m] = temp;
                m++;
                l++;
            }
            else {
                l++;
            }
        }
        return m;
    }
public static void qsort (int[] data, int l, int r) {
        if (l<r) {
        qsort (data, l, partition (data, l, r)-1); //Aufruf für linke Subarrays
        qsort (data, partition (data, l, r)+1, r); //Aufruf für rechte Subarrays
        }
    }
public static void qsort (int[] data) { //Aufruf für Gesamtarray
        qsort (data, 0, data.length-1);
    }
}
