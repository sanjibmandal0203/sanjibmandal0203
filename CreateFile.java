import java.io.File;
import java.io.IOException;
import java.util.Scanner;
public class CreateFile{
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter File Name : ");
        String a=new sc.nextLine();
        File myFile=new File(a);
        try{
            if(myFile.createNewFile()){
                System.out.println("File Created : "+a+" Successfully");
            }
            else{
                System.out.println("File Already exist.");
            }
        }
        catch(IOException e){
            System.out.println("An error occurde.");
            e.printStackTrace();
        }
    }
}