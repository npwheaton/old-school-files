
public class EvolAlgorithm {
    public static void main(String[] args){
        int generations = 0;
        int setsize = 0;
        int initpop = 0;
        double mutationchance = 0.0;
        double crosschance = 0.0;
        EvolDisplay d = new EvolDisplay();

        //ask for initial numbers
        try {
            String temp = "";
            temp = d.input("Enter the number of generations: ");
    generations = Integer.parseInt(temp);
           } catch (NumberFormatException nfe) 
            {System.exit(0);}

        try {
            String temp = "";
            temp = d.input("Enter the size of the sets: ");
    setsize = Integer.parseInt(temp);
           } catch (NumberFormatException nfe) 
            {System.exit(0);}   

        try {
            String temp = "";
            temp = d.input("Enter the size of the initial population");
    initpop = Integer.parseInt(temp);
           } catch (NumberFormatException nfe) 
            {System.exit(0);}    

         try {
            String temp = "";
            temp = d.input("Enter the number of Mutation chance: ");
    mutationchance = Double.parseDouble(temp);
           } catch (NumberFormatException nfe) 
            {System.exit(0);}      

          try {
            String temp = "";
            temp = d.input("Enter the number of Crossover chance: ");
    crosschance = Double.parseDouble(temp);
           } catch (NumberFormatException nfe) 
            {System.exit(0);}        
    
        
        NumberSet nset= new NumberSet(setsize);
        nset.populateSet();
        PopulationControl population = new PopulationControl(initpop);
        population.generatepopulation(nset);
        d.GetNumset(nset);
        //loop for program
        for (int i = 0; i<generations; i++)
            {//calculate average fit, highest fit
                population.FindAvg();
                population.findhighfit();
                //make children
                population.reproduce(mutationchance, crosschance, nset);
                
                //update evolution display
                d.endstats(population.sendhigh(),population.sendAvg(),population.SendChromo(), i, generations);
            }
            
    }

}
