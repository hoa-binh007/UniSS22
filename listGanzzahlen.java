import java.util.Scanner;
import java.util.ArrayList;
import java.util.Arrays;


class listGanzzahlen{
	public static void main (String[]args){

		
		Scanner input = new Scanner(System.in);
		ArrayList <Integer> list = new ArrayList<Integer>();

		try{

			while (input.hasNext()){
		
				list.add(Integer.parseInt(input.next()));
			}

			
		
			
		}

		catch (NumberFormatException e) {
           	System.out.println("The arguments must be integers.");
           	return;
		}

			int [] array = new int[list.size()];
			for(int  i=0;i<list.size();i++){
				array[i]= (Integer)list.get(i);
			}

		System.out.println("Liste:" ); 
		System.out.println(Arrays.toString(array));
	}
}