//
// Vector.hh for  in /home/lecoq_m/basics_cpp
// 
// Made by Maxime LECOQ
// Login   <lecoq_m@epitech.net>
// 
// Started on  Sun Apr 24 21:20:40 2016 Maxime LECOQ
// Last update Tue Dec 20 03:24:22 2016 lecoq
//

#ifndef		__VECTOR_HH__
# define	__VECTOR_HH__

# include       <iostream>
# include       <string>
# include       <vector>

namespace Tools {
  /* La classe Vector permet de gerer le passage de string en tableau de string et inversement. */
  class		Vector
  {
  public:
    /* La classe Vectorize permet de gerer le passage de string en tableau de string. */
    class           Vectorize
    {
    private:
      std::vector<std::string>      _vec;
    public:
      Vectorize();
      Vectorize(const std::string &, const char &);
      ~Vectorize();
      Vectorize(const Vectorize &);
      Vectorize &operator=(const Vectorize &);
    public:
      /* La méthode getVector() const permet de recuperer le tableau de string */
      std::vector<std::string>      getVector() const;
      /* La méthode getVector(const std::string &, const char &) const permet de recuperer un tableau de string en fonction d'une chaîne de caractère et séparer par un délimiteur. */
      std::vector<std::string>      getVector(const std::string &, const char &);
      std::vector<std::string>      getVector(const std::string &, const char *);
      /* La méthode getVector(const std::string &, const char &) const permet de recuperer un tableau de string en fonction d'une chaîne de caractère et séparer par un délimiteur. */
      std::vector<std::string>      getVector(const char *, const char &);
      std::vector<std::string>      getVector(const char *, const char *);
    };
    /* La classe Devectorize permet de gerer le passage de tableau de string en string. */
    class           Devectorize
    {
    private:
      std::string           _str;
    public:
      Devectorize();
      Devectorize(const std::vector<std::string> &, const char &);
      ~Devectorize();
      Devectorize(const Devectorize &);
      Devectorize &operator=(const Devectorize &);
    public:
      /* La méthode getString() const permet de recuperer une string. */
      const std::string     &getString() const;
      /* La méthode getString(std::vector<std::string> &, const char &) const permet de recuperer une string à partir d'un tableau de string en fonction d'un délimiteur. */
      std::string           getString(std::vector<std::string> &, const char &);
    };
  private:
    Vectorize		_v;
    Devectorize		_d;
  public:
    Vector();
    ~Vector();
    Vector(const Vector &);
    Vector &operator=(const Vector &);

    /* La méthode getVector(const std::string &, const char &) utiliser Vectorize pour récupérer un tableau de string. */
    std::vector<std::string>	getVector(const std::string &, const char &);
    std::vector<std::string>	getVector(const std::string &, const char *);
    /* La méthode getVector(const std::string &, const char &) utiliser Vectorize pour récupérer un tableau de string. */
    std::vector<std::string>	getVector(const char *, const char &);
    std::vector<std::string>	getVector(const char *, const char *);
    /* La méthode getString(std::vector<std::string> &, const char &) utiliser Devectorize pour récupérer une string. */
    std::string			getString(std::vector<std::string> &, const char &);
  };
};

using namespace Tools;

#endif
