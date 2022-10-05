public class Main {
	private static long stopTime;
	private static long startTime;

	/*---------------------- alinea a) ----------------------*/
	static void ex1a(long n){
		long soma=0;
		startTimer();
		for(long i=0;i<n;i++)
			for(long j=0;j<n;j++)
				soma++;
		System.out.println("Soma (a) ="+soma);
		stopTimer();
		showTime();
	}

	/*---------------------- alinea b) ----------------------*/
	static void ex1b(long n){
		long soma=0;
		startTimer();
		for(long i=0;i<n;i++)
					soma++;
		System.out.println("Soma (b)="+soma);
		stopTimer();
		showTime();
	}

	/*---------------------- alinea c) ----------------------*/
	static void ex1c(long n){
		long soma=0;
		startTimer();
		for(long i=0;i<n;i++)
			soma++;
		System.out.println("Soma (c) ="+soma);
		stopTimer();
		showTime();
	}

	/*---------------------- alinea d) ----------------------*/
	static void ex1d(long n){
		long soma=0;
		startTimer();
		for(long i=0;i<n;i++)
			soma++;
		System.out.println("Soma (d)="+soma);
		stopTimer();
		showTime();
	}

	/*---------------------- alinea e) ----------------------*/
	static void ex1e(long n){
		long soma=0;
		startTimer();
		for(long i=0;i<n;i++)
			soma++;
		System.out.println("Soma="+soma);
		stopTimer();
		showTime();
	}

	/*---------------------- alinea f) ----------------------*/
	static void ex1f(long n){
		long soma=0;
		startTimer();
		for(long i=0;i<n;i++)
			soma++;
		System.out.println("Soma="+soma);
		stopTimer();
		showTime();
	}

	/*---------------------- alinea g) ----------------------*/
	static void ex1g(long n){
		long soma=0;
		startTimer();
		for(long i=0;i<n;i++)
			soma++;
		System.out.println("Soma="+soma);
		stopTimer();
		showTime();
	}

	/*---------------------- alinea h) ----------------------*/
	static void ex1h(long n){
		long soma=0;
		startTimer();
		for(long i=0;i<n;i++)
			soma++;
		System.out.println("Soma="+soma);
		stopTimer();
		showTime();
	}

	private static void showTime() {
		long interval=stopTime-startTime;
		long secs=interval/1000000000L;
		long decs=interval-secs*1000000000L;
		decs/=100000000L;
		System.out.println("secs="+secs+"."+decs);
	}
	private static void stopTimer() {
		stopTime=System.nanoTime();
	}
	private static void startTimer() {
		startTime=System.nanoTime();
	}
	public static void main(String[] args) {
		int n = 12000;
		System.out.print("a) = "); ex1a(n);
		System.out.print("a) 4x = "); ex1a(4 * n);

		System.out.print("b) = "); ex1b(2000000000L);
		System.out.print("b) 4x = "); ex1b(4 * 2000000000L);

		System.out.print("c) = "); ex1c(2000000000L);
		System.out.print("c) 4x = "); ex1c(4 * 2000000000L);

		System.out.print("d) = "); ex1d(2000000000L);
		System.out.print("d) 4x = "); ex1d(4 * 2000000000L);

		System.out.print("e) = "); ex1e(2000000000L);
		System.out.print("e) 4x = "); ex1e(4 * 2000000000L);
	}
}
