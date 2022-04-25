import java.util.Arrays;
import java.util.Scanner;
import java.util.ArrayList;

public class AssertionTest {

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
            output[2] = 3;
            assert isSorted (output) : "Order not correct.";
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


public static int[] partition (int[] data, int l, int r) {
        if (l>=r) { //Abbruchbedingung, höchstens ein Element enthalten
            int[] arr = {0,0};
            return arr;
        }
        if (data[l] < data[r]) { // Ist das linke Pivot kleiner als das rechte, müssen sie vertauscht werden
        int temp = data[l];
        data[l] = data[r];
        data[r] = temp;
        }
        int m_1 = l;
        int m_2 = r;
        // Die Variable l fungiert im Folgenden gewissermaßen als Zeiger auf das nächste zu vergleichende Element des (Teil-)Arrays
        l++;
        while (l<m_2) { //Vergleiche aller anderen Elemente mit Pivot, bis rechte Arraygrenze erreicht ist
            if (data[l]> data[m_1]) { //Ist das zu untersuchende Element größer als m_1, wird es mit m_1 vertauscht und befindet sich im linken subarray
                int temp = data[l];
                data[l] = data[m_1];
                data[m_1] = temp;
                m_1 = l;
                l++;
            }
            else {
                if (data[l] < data[m_2]) { //Ist das zu untersuchende Element kleiner als m_2, wird es gewissermaßen nach rechts auf den Platz von m_2 verschoben:
                    int temp = data[l];
                    for (int i = l; i<m_2; i++) {
                        data[i] = data[i+1];
                    }
                    data[m_2] = temp;
                    m_2--;
                }
                else l++; // Ist das zu untersuchende Element weder kleiner als m_2 noch größer als m_1, ist es bereits richtig platziert, kein Tausch
            }
        }
        int [] pivots = {m_1, m_2};
        return pivots;
    }
public static void qsort (int[] data, int l, int r) {
        if (l<r) {
        qsort (data, l, ((partition (data, l, r))[0])-1); //Aufruf für linke Subarrays
        qsort (data, ((partition (data, l, r))[0])+1, ((partition (data, l, r))[1])-1); //Aufruf für mittige Subarrays
        qsort (data, ((partition (data, l, r))[1])+1, r); //Aufruf für rechte Subarrays
        }
    }
public static void qsort (int[] data) { //Aufruf für Gesamtarray
        qsort (data, 0, data.length-1);
    }
public static boolean isSorted (int[] data) {
    for (int i = 1; i < data.length; i++) {
        if (data[i] > data[i-1]) return false;
    }
    return true;
    }

}
