#ifndef ARBREBINAIRE_H__
#define ARBREBINAIRE_H__
#include <float.h>


template <class T>
class ArbreBinaire
{
public:
	ArbreBinaire();
	~ArbreBinaire();

	void Afficher();
	void Ajouter(const T& valeur);
	void Enlever(const T& valeur);
	void Vider();
	bool Contient(const T& valeur);
	int Nombre() const;

	const T& Minimum() const;
	const T& Maximum() const;
	void AfficherCroissant() const;
	void AfficherDecroissant() const;

private:
	struct Noeud
	{
		T valeur;
		Noeud* gauche = nullptr;
		Noeud* droite = nullptr;

		Noeud(const T& valeur, Noeud* gauche, Noeud* droite) : valeur(valeur), gauche(gauche), droite(droite) {}
	};

	void Vider(Noeud* noeud);
	Noeud* m_debut = nullptr;
	int m_count = 0;
};

template <class T>
ArbreBinaire<T>::ArbreBinaire()
{
}

template <class T>
ArbreBinaire<T>::~ArbreBinaire()
{
	Vider();
}

template <class T>
void ArbreBinaire<T>::Afficher()
{
}

template <class T>
void ArbreBinaire<T>::Ajouter(const T& valeur)
{
	Noeud* n = m_debut;

	if (m_count == 0)
	{
		m_debut = new Noeud*(valeur);
		++m_count;
	}

	while (n->valeur != valeur)
	{
		if (valeur < n->valeur)
		{
			if (!n->gauche)
			{
				n->gauche = new Noeud*(valeur);
				++m_count;
				n = n->gauche;
			}
			else
				n = n->gauche;
		}

		else if (valeur > n->valeur)
		{
			if (!n->droite)
			{
				n->droite = new Noeud*(valeur);
				++m_count;
				n = n->droite;
			}
			else
				n = n->droite;
		}
	}

}

template <class T>
void ArbreBinaire<T>::Enlever(const T& valeur)
{

}

template <class T>
void ArbreBinaire<T>::Vider()
{
	Vider(m_debut);
}

template <class T>
void ArbreBinaire<T>::Vider(Noeud* noeud)
{
	if(noeud->gauche)
		Vider(noeud->gauche);

	if (noeud->droite)
		Vider(noeud->droite);

	delete noeud;
	--m_count;
}

template <class T>
bool ArbreBinaire<T>::Contient(const T& valeur)
{
	Noeud* n = m_debut;

	if (m_count == 0)
		return false;

	while (n->valeur != valeur)
	{
		if (valeur < n->valeur)
		{
			if (!n->gauche)
				return false;
			else
				n = n->gauche;
		}

		else if (valeur > n->valeur)
		{
			if (!n->droite)
				return false;
			else
				n = n->droite;
		}
	}

	return true;
}

template <class T>
int ArbreBinaire<T>::Nombre() const
{
	return m_count;
}

template <class T>
const T& ArbreBinaire<T>::Minimum() const
{
	Noeud* n = m_debut;

	if (m_count == 0)
		return;

	while (n)
	{
		if (n->gauche)
			n = n->gauche;
		else
			return n->valeur;
	}

	return;
}

template <class T>
const T& ArbreBinaire<T>::Maximum() const
{
	Noeud* n = m_debut;

	if (m_count == 0)
		return;

	while (n)
	{
		if (n->droite)
			n = n->droite;
		else
			return n->valeur;
	}

	return;
}

template <class T>
void ArbreBinaire<T>::AfficherCroissant() const
{
}

template <class T>
void ArbreBinaire<T>::AfficherDecroissant() const
{
}

#endif
