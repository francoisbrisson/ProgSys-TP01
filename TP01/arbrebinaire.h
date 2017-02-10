#ifndef ARBREBINAIRE_H__
#define ARBREBINAIRE_H__
#include <float.h>
#include <string>
#include <sstream>
#include <algorithm>

// Compiler sur linux avec la commande g++ --std=c++0x ./main.cpp

template <class T>
class ArbreBinaire
{
public:
	ArbreBinaire();
	~ArbreBinaire();

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

	T m_dummy;
	void Vider(Noeud* noeud);
	void EnleverNoeud(Noeud* precedent, Noeud* noeud);
	Noeud* m_debut = nullptr;
	int m_count = 0;
	void AfficherCroissant(Noeud* noeud) const;
	void AfficherDecroissant(Noeud* noeud) const;
	static bool EstADroite(Noeud* parent, Noeud* enfant);

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
void ArbreBinaire<T>::Ajouter(const T& valeur)
{
	Noeud* n = m_debut;

	if (m_count == 0)
	{
		m_debut = new Noeud(valeur, nullptr, nullptr);
		++m_count;
		return;
	}

	while (n->valeur != valeur)
	{

		if (valeur < n->valeur)
		{
			if (!n->gauche)
			{
				n->gauche = new Noeud(valeur, nullptr, nullptr);
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
				n->droite = new Noeud(valeur, nullptr, nullptr);
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
	Noeud* n = m_debut;
	Noeud* precedent = nullptr;

	if (m_count == 0)
		return;

	while (n->valeur != valeur)
	{
		if (valeur < n->valeur)
		{
			if (!n->gauche)
				return;
			else
			{
				precedent = n;
				n = n->gauche;
			}
		}

		else if (valeur > n->valeur)
		{
			if (!n->droite)
				return;
			else
			{
				precedent = n;
				n = n->droite;
			}
		}
	}

	EnleverNoeud(precedent, n);
}

template <class T>
void ArbreBinaire<T>::EnleverNoeud(Noeud* precedent, Noeud* noeud)
{
	Noeud* n = nullptr;
	Noeud* precedentSousNoeud = nullptr;

	if (!noeud->gauche && !noeud->droite)
	{
		if (EstADroite(precedent, noeud))
			precedent->droite = nullptr;
		else
			precedent->gauche = nullptr;
	}
	if (!noeud->gauche && noeud->droite)
	{
		if (EstADroite(precedent, noeud))
			precedent->droite = noeud->droite;
		else
			precedent->gauche = noeud->droite;
	}
	else if (noeud->gauche && !noeud->droite)
	{
		if (EstADroite(precedent, noeud))
			precedent->droite = noeud->gauche;
		else
			precedent->gauche = noeud->gauche;
	}
	else if (noeud->gauche && noeud->droite)
	{
		n = noeud->droite;
		if (!n->gauche && !n->droite)
		{
			noeud->droite = nullptr;
			noeud->valeur = n->valeur;
		}

		else if (n->gauche)
		{
			while (n->gauche)
			{
				precedentSousNoeud = n;
				n = n->gauche;
			}
			if (n->droite)
				precedentSousNoeud->gauche = n->droite;
			else
				precedent->gauche = nullptr;

			noeud->valeur = n->valeur;
		}
		else
				noeud->droite = n->droite;

		delete n;
		--m_count;
		return;
	}
	delete noeud;
	--m_count;
}

template <class T>
void ArbreBinaire<T>::Vider()
{
	Vider(m_debut);
}

template <class T>
void ArbreBinaire<T>::Vider(Noeud* noeud)
{
	if (!m_debut)
		return;

	if (noeud->gauche)
		Vider(noeud->gauche);

	if (noeud->droite)
		Vider(noeud->droite);

	delete noeud;
	--m_count;

	if (m_count == 0)
		m_debut = nullptr;

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
		return m_dummy;

	while (n)
	{
		if (n->gauche)
			n = n->gauche;
		else
			return n->valeur;
	}

	return m_dummy;
}

template <class T>
const T& ArbreBinaire<T>::Maximum() const
{
	Noeud* n = m_debut;

	if (m_count == 0)
		return m_dummy;

	while (n)
	{
		if (n->droite)
			n = n->droite;
		else
			return n->valeur;
	}

	return m_dummy;
}

template <class T>
void ArbreBinaire<T>::AfficherCroissant() const
{
	AfficherCroissant(m_debut);
}

template <class T>
void ArbreBinaire<T>::AfficherCroissant(Noeud* noeud) const
{
	if (!m_debut)
		return;

	if (noeud->gauche)
		AfficherCroissant(noeud->gauche);
	std::cout << noeud->valeur << std::endl;
	if (noeud->droite)
		AfficherCroissant(noeud->droite);
}

template <class T>
void ArbreBinaire<T>::AfficherDecroissant() const
{
	AfficherDecroissant(m_debut);
}

template <class T>
void ArbreBinaire<T>::AfficherDecroissant(Noeud* noeud) const
{
	if (!m_debut)
		return;

	if (noeud->droite)
		AfficherDecroissant(noeud->droite);
	std::cout << noeud->valeur << std::endl;
	if (noeud->gauche)
		AfficherDecroissant(noeud->gauche);
}

template <class T>
bool ArbreBinaire<T>::EstADroite(Noeud* parent, Noeud* enfant)
{
	if (parent->valeur < enfant->valeur)
		return true;
	else
		return false;
}

#endif
