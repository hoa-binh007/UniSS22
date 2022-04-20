
import java.util.Scanner;
import java.util.Arrays;
import java.util.ArrayList;

public class Aufgabe1_2{

	public static void main(String[]args){
	
		Scanner input = new Scanner(System.in);
		ArrayList <Integer> list = new ArrayList<Integer>();
		while (input.hasNextLine()){

			try{
				list.add(Integer.parseInt (input.nextLine()));
			} catch (NumberFormatException e){
				System.err.println("Input list contains a non-number.");
				return;
			}
		}

		int [] array = new int [list.size()];
			for (int i = 0; i < list.size(); i++){
			array[i] = (Integer)list.get(i);
			}

		System.out.println(Arrays.toString(array));
		printPermutations(array,0);

	}

	public static int printPermutations( int [] array, int d){

	if(array.length-d == 1){
		System.out.println(Arrays.toString(array));
	} else{
		for(int i=0; i < array.length-d-1 ; i++){
			printPermutations(array, d + 1);

			if((array.length-d)%2==1){
			int temp = array[array.length-d-1];
			array[array.length-d-1] = array[0];
			array[0] = temp;
			}
				else{
				int temp = array[i];
				array[i] = array[array.length-d-1];
				array [array.length-d-1]  = temp;
				}
		
		}
		printPermutations(array, d+1);
	}

	return 0;
	}

}
