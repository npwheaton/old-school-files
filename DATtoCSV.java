import java.io.File;
import java.io.FileWriter;
import java.util.Scanner;

public class DATtoCSV {
    
    private static String comma = ",";
    private static String newLine = "\n";

    public static void main(String[] args){
        //get filename input
        System.out.println("enter the file name");
        Scanner answer = new Scanner(System.in);
        String filename = answer.nextLine();
        File datFile = new File(filename);
        answer.close();

        
        try {
            Scanner filereader = new Scanner(datFile);
            String[] originalFileArray = filename.split("\\.");
            String endFilename = originalFileArray[0] + "(converted to .CSV)" + ".csv";
            File csvFile = new File(endFilename);
            FileWriter fwriter = new FileWriter(csvFile);
            while(filereader.hasNext()){
                String fileOutput = filereader.nextLine();
                fileOutput = fileOutput.trim();
                String fileOutputArray[] = fileOutput.split("\\s+");
                String endOutput = "";
                for(int i = 0; i<fileOutputArray.length; i++){
                    if(i ==(fileOutputArray.length-1)){
                        endOutput+= fileOutputArray[i];
                    }
                    else{
                        endOutput+=fileOutputArray[i]+ comma;
                    }
                }
                endOutput+= newLine;
                fwriter.append(endOutput);

            }
            filereader.close();
            fwriter.close();
        


        }catch(Exception e){
            System.out.println("File could not be found");
            e.printStackTrace();
        }
    }
}