import javax.swing.JOptionPane;

public class GraphEvolAlgorithm {
    public static String input(String Prompt) {
        String ans = JOptionPane.showInputDialog(Prompt);
        return ans;
    }

    public static void main(String[] args) {
        int generations = 0;
        int setsize = 0;
        int initpop = 0;
        double mutationchance = 0.0;
        double crosschance = 0.0;

        // ask for initial numbers
        try {
            String temp = "";
            temp = input("Enter the number of generations: ");
    generations = Integer.parseInt(temp);
           } catch (NumberFormatException nfe) 
            {System.exit(0);}

        try {
            String temp = "";
            temp = input("Enter the number of vertices: ");
    setsize = Integer.parseInt(temp);
           } catch (NumberFormatException nfe) 
            {System.exit(0);}   

        try {
            String temp = "";
            temp = input("Enter the size of the initial population");
    initpop = Integer.parseInt(temp);
           } catch (NumberFormatException nfe) 
            {System.exit(0);}    

         try {
            String temp = "";
            temp = input("Enter the number of Mutation chance: ");
    mutationchance = Double.parseDouble(temp);
           } catch (NumberFormatException nfe) 
            {System.exit(0);}      

          try {
            String temp = "";
            temp = input("Enter the number of Crossover chance: ");
    crosschance = Double.parseDouble(temp);
           } catch (NumberFormatException nfe) 
            {System.exit(0);}        

        Graphset gset= new Graphset(setsize);
        Grapheuristic gph = new Grapheuristic(gset);
        gph.makeGraph();
        gset.populateSet();
        Graphcontrol population = new Graphcontrol(initpop, gset);
        population.generatepopulation();
        GraphEvolDisplay d = new GraphEvolDisplay(gset);
        //loop for program
        for (int i = 0; i<generations; i++)
            {//calculate average fit, highest fit
                population.disqualifybadgraphs();
                //make children
                population.reproduce(mutationchance, crosschance);
                
                //update evolution display
                d.endstats(population.sendhigh(),population.sendAvg(),population.Sendgraph(), i, generations, gph);
            }
            
}
}