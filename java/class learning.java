import java.util.*;



class Bowling {

	HashMap<String, Integer> players;

	Bowling() {

		players = new HashMap<String, Integer>();

	}

	public void addPlayer(String name, int p) {

		players.put(name, p);

	}

	//your code goes here

	public void getWinner() {
		int pl = 0;
		String na ="";
		Set<String> k = players.keySet();
		for (Iterator i = k.iterator(); i.hasNext();) {
			String w = i.next().toString();
			if (players.get(w) > pl) {
				pl = players.get(w);
				na = w;
			}
		}
		System.out.println(na);
	}
}

public class Main {

	public static void main(String[ ] args) {

		Bowling game = new Bowling();

		Scanner sc = new Scanner(System.in);



		for (int i = 0; i < 3; i++) {

			String input = sc.nextLine();

			String[] values = input.split(" ");

			String name = values[0];

			int points = Integer.parseInt(values[1]);

			game.addPlayer(name, points);

		}

		game.getWinner();

	}
}
