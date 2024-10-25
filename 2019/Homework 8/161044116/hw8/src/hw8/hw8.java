package hw8;

public class hw8
{
	public static void main(String[] args) throws Exception
	{
		System.out.println("**************For Set (integer)****************");
		GTUSet<Integer> Setint = new GTUSet<>();
		
		System.out.println("Inserting(1-3-2-5-4-6-8-7)");
		try {
			Setint.insert(1);
			Setint.insert(3);
			Setint.insert(2);
			Setint.insert(5);
			Setint.insert(4);
			Setint.insert(4);
			Setint.insert(8);
			Setint.insert(7);
		} catch(IllegalArgumentException e) {
			e.printStackTrace();
			System.err.println("This is left in as a demonstration.");
		}
		
		System.out.println("Set is size: "+ Setint.size());
		System.out.print("Set in contents: ");
		Setint.print();
		
		System.out.print("\nTest Iterator: ");
		for (Integer current : Setint)
			System.out.print(current+" ");
		
		System.out.print("\nErasing(3-2-1)");
		Setint.erase(3);
		Setint.erase(1);
		Setint.erase(2);
		System.out.print("\nSet in contents: ");
		Setint.print();
		System.out.print("\nSet is size: "+ Setint.size());
		
		if(Setint.contains(9))
			System.out.print("\nThere is  the obje(9) in Set.");
		else
			System.out.print("\nThere is not  the obje(9) in Set!");
			Setint.clear();
		
		if(Setint.empty())
			System.out.print("\nSet is Clear..");
		else
			System.out.print("\nSet is Not Clear..");		
	
		System.out.println("**************For Set (String)****************");
		GTUSet<String> Setistring = new GTUSet<>();
		
		System.out.println("Inserting(rock and roll- pop- blues- dance- country- jazz- rhythm and blues -hip-hop)");
		Setistring.insert("rock and roll");
		Setistring.insert("pop");
		Setistring.insert("blues");
		Setistring.insert("dance");
		Setistring.insert("country");
		Setistring.insert("jazz");
		Setistring.insert("rhythm and blues");
		Setistring.insert("hip-hop");
		System.out.println("Set is size: "+ Setistring.size());
		System.out.print("Set in contents: ");
		Setistring.print();
		
		System.out.print("\nTest Iterator: ");
		for (String current : Setistring)
			System.out.print(current+" ");
		
		System.out.print("\nErasing(3-2-1)");
		Setistring.erase("hip-hop");
		Setistring.erase("rhythm and blues");
		Setistring.erase("country");
		System.out.print("\nSet in contents: ");
		Setistring.print();
		System.out.print("\nSet is size: "+ Setistring.size());
		
		if(Setistring.contains("turkish music"))
			System.out.print("\nThere is  the obje(turkish music) in Set.");
		else
			System.out.print("\nThere is not  the obje(turkish music) in Set!");
		Setistring.clear();
		
		if(Setistring.empty())
			System.out.print("\nSet is Clear..");
		else
			System.out.print("\nSet is Not Clear..");
		
		System.out.println("**************For Vector (integer)****************");
		GTUVector<Integer> vectint = new GTUVector<>();
		
		System.out.println("Inserting(1-3-2-5-4-6-8-7)");
		vectint.insert(1);
		vectint.insert(3);
		vectint.insert(2);
		vectint.insert(5);
		vectint.insert(4);
		vectint.insert(4);
		vectint.insert(8);
		vectint.insert(7);
		System.out.println("Set is size: "+ vectint.size());
		System.out.print("Set in contents: ");
		vectint.print();
		
		System.out.print("\nTest Iterator: ");
		for (Integer current : vectint)
			System.out.print(current+" ");
		
		System.out.print("\nErasing(3-2-1)");
		vectint.erase(7);
		vectint.erase(1);
		vectint.erase(2);
		System.out.print("\nSet in contents: ");
		vectint.print();
		System.out.print("\nSet is size: "+ vectint.size());
		
		if(vectint.contains(9))
			System.out.print("\nThere is  the obje(9) in Set.");
		else
			System.out.print("\nThere is not  the obje(9) in Set!");
		vectint.clear();
		
		if(vectint.empty())
			System.out.print("\nSet is Clear..");
		else
			System.out.print("\nSet is Not Clear..");
		
		System.out.println("**************For Vector (String)****************");
		GTUVector<String> vecstring = new GTUVector<>();
		
		System.out.println("Inserting(rock and roll- pop- blues- dance- country- jazz- rhythm and blues -hip-hop)");
		vecstring.insert("rock and roll");
		vecstring.insert("pop");
		vecstring.insert("blues");
		vecstring.insert("dance");
		vecstring.insert("country");
		vecstring.insert("jazz");
		vecstring.insert("rhythm and blues");
		vecstring.insert("hip-hop");
		System.out.println("Set is size: "+ vecstring.size());
		System.out.print("Set in contents: ");
		vecstring.print();
		
		System.out.print("\nTest Iterator: ");
		for (String current : vecstring)
			System.out.print(current+" ");
		
		System.out.print("\nErasing(3-2-1)");
		vecstring.erase("hip-hop");
		vecstring.erase("rhythm and blues");
		vecstring.erase("country");
		System.out.print("\nSet in contents: ");
		vecstring.print();
		System.out.print("\nSet is size: "+ vecstring.size());
		
		if(vecstring.contains("turkish music"))
			System.out.print("\nThere is  the obje(turkish music) in Set.");
		else
			System.out.print("\nThere is not  the obje(turkish music) in Set!");
		vecstring.clear();
		
		if(vecstring.empty())
			System.out.print("\nSet is Clear..");
		else
			System.out.print("\nSet is Not Clear..");
	}
	
}
