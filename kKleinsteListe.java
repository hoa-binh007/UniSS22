import java.util.Scanner;
import java.util.ArrayList;
import java.util.Arrays;


class kKleinsteListe{
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
			array[i]=(Integer)list.get(i);
		}
		int k = 0;

		try{
			if(args.length==0){
				System.out.println("Gebe bitte k ein:");
				k = input.nextInt();
			}
			else{
				k = Integer.parseInt(args[0]);
			}
			if(k>array.length){
				throw new IndexOutOfBoundsException();

			}
			
				
		} 
		catch (NumberFormatException e){
			System.err.println("k is a non-number.");
			
		}
		catch (IndexOutOfBoundsException e){
			System.out.println("This list must contain at least k=" +k+ "numbers, but only" +array.length+ "were provided");
		}



		System.out.println("Liste:" ); 
		System.out.println(Arrays.toString(array));
		Arrays.sort(array);
		System.out.println("The" +k+ "smallest value is: " +array[k-1]);

	}
}