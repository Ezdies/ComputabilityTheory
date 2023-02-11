#include <iostream>
#include <cmath>
#include <vector>

template <int N>
class Statement
{
};

template <>
class Statement<1>
{

public:
	Statement(int m) : m(m) {}
	int m;
};

template <>
class Statement<2>
{

public:
	Statement(int m, int n) : m(m), n(n) {}
	int m;
	int n;
};

template <>
class Statement<3>
{
public:
	Statement(int m, int n, int q) : m(m), n(n), q(q) {}
	int m;
	int n;
	int q;
};

int pi(int m, int n)
{
	return (pow(2, m) * (2 * n + 1)) - 1;
}

int zeta(int m, int n, int q)
{
	return pi(pi(m - 1, n - 1), q - 1);
}

int bi_z(int n)
{
	return 4 * (n - 1);
}

int bi_s(int n)
{
	return bi_z(n) + 1;
}

int bi_t(int m, int n)
{
	return 4 * pi(m - 1, n - 1) + 2;
}

int bi_j(int m, int n, int q)
{
	return 4 * zeta(m, n, q) + 3;
}

void get_z(int n, std::vector<Statement<1>> &z_statements)
{
	for (int i = 0; i < n; i++)
	{
		int m;
		std::cout << "Podaj m\n";
		std::cin >> m;
		z_statements.push_back(Statement<1>(m));
	}
}

void get_s(int n, std::vector<Statement<1>> &s_statements)
{
	for (int i = 0; i < n; i++)
	{
		int m;
		std::cout << "Podaj m\n";
		std::cin >> m;
		
		s_statements.push_back(Statement<1>(m));
	}
}

void get_t(int n, std::vector<Statement<2>> &t_statements)
{
	for (int i = 0; i < n; i++)
	{
		int m;
		int n;
		std::cout << "Podaj m\n";
		std::cin >> m;
		std::cout << "Podaj n\n";
		std::cin >> n;
		
		t_statements.push_back(Statement<2>(m, n));
	}
}

void get_j(int n, std::vector<Statement<3>> &j_statements)
{
	for (int i = 0; i < n; i++)
	{
		int m;
		int n;
		int q;
		std::cout << "Podaj m\n";
		std::cin >> m;
		std::cout << "Podaj n\n";
		std::cin >> n;
		std::cout << "Podaj q\n";
		std::cin >> q;
		j_statements.push_back(Statement<3>(m, n, q));
	}
}

void get_input(std::vector<Statement<1>> &z_statements,
			   std::vector<Statement<1>> &s_statements,
			   std::vector<Statement<2>> &t_statements,
			   std::vector<Statement<3>> &j_statements)
{
	int n;

	std::cout << "Podaj liczbe instrukcji\n";
	std::cin >> n;

	int z_count = 0;

	std::cout << "Podaj liczbę instrukcji Z\n";
	std::cin >> z_count;

	get_z(z_count, z_statements);

	int s_count = 0;

	std::cout << "Podaj liczbę instrukcji S\n";
	std::cin >> s_count;

	get_s(s_count, s_statements);

	int t_count = 0;

	std::cout << "Podaj liczbę instrukcji T\n";
	std::cin >> t_count;

	get_t(t_count, t_statements);

	int j_count = 0;

	std::cout << "Podaj liczbę instrukcji J\n";
	std::cin >> j_count;

	get_j(j_count, j_statements);
}

void count_data(std::vector<Statement<1>> &z_statements,
				std::vector<Statement<1>> &s_statements,
				std::vector<Statement<2>> &t_statements,
				std::vector<Statement<3>> &j_statements,
				std::vector<int> &b_Zs,
				std::vector<int> &b_Ss,
				std::vector<int> &b_Ts,
				std::vector<int> &b_Js)
{
	for (const auto &z : z_statements)
	{
		b_Zs.push_back(bi_z(z.m));
	}

	for (const auto &s : s_statements)
	{
		b_Ss.push_back(bi_s(s.m));
	}

	for (const auto &t : t_statements)
	{
		b_Ts.push_back(bi_t(t.m, t.n));
	}

	for (const auto &j : j_statements)
	{
		b_Js.push_back(bi_j(j.m, j.n, j.q));
	}
}

void print_data(std::vector<int> &b_Zs,
				std::vector<int> &b_Ss,
				std::vector<int> &b_Ts,
				std::vector<int> &b_Js)
{
	std::cout << "Z: ";
	for (const auto &z : b_Zs)
	{
		std::cout << z << " ";
	}
	std::cout << "\n";

	std::cout << "S: ";
	for (const auto &s : b_Ss)
	{
		std::cout << s << " ";
	}
	std::cout << "\n";

	std::cout << "T: ";
	for (const auto &t : b_Ts)
	{
		std::cout << t << " ";
	}
	std::cout << "\n";

	std::cout << "J: ";
	for (const auto &j : b_Js)
	{
		std::cout << j << " ";
	}
	std::cout << "\n";
}

int main()
{
	std::vector<Statement<1>> z_statements;
	std::vector<Statement<1>> s_statements;
	std::vector<Statement<2>> t_statements;
	std::vector<Statement<3>> j_statements;

	get_input(z_statements, s_statements, t_statements, j_statements);

	std::vector<int> b_Zs;
	std::vector<int> b_Ss;
	std::vector<int> b_Ts;
	std::vector<int> b_Js;

	count_data(z_statements, s_statements, t_statements, j_statements, b_Zs, b_Ss, b_Ts, b_Js);

	print_data(b_Zs, b_Ss, b_Ts, b_Js);
}
