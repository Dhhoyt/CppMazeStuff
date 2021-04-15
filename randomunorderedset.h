#include <unordered_set>
#include <functional>
#include <vector>
#include <memory>
#include <random>

//stolen from https://stackoverflow.com/a/51973872

template <class T>
class RandomUnorderedSet
{
private:
   struct Entry {
       Entry(const T & data_in, unsigned index_in_vector_in)
       : data(data_in), index_in_vector(index_in_vector_in) 
       {}
       T data;
       unsigned index_in_vector;
   };
   struct PtrEntryHash {
       auto operator()(const std::unique_ptr<Entry> & entry) const 
       { 
           return std::hash<T>()(entry->data);
       }
   };
   struct PtrEntryEqual {
       bool operator()(const std::unique_ptr<Entry> & a, 
                       const std::unique_ptr<Entry> & b ) const 
       { 
           return a->data == b->data;
       }
   };
public:
   bool insert(const T & element)
   {
       auto entry_ptr = std::make_unique<Entry>(element, m_entry_vector.size());
       if (m_entry_set.count(entry_ptr) > 0)
          return false;
       m_entry_vector.push_back(entry_ptr.get());
       try {
            m_entry_set.insert(std::move(entry_ptr));
       } catch(...) {
           m_entry_vector.pop_back();
           throw;
       }
       return true;
   }

   size_t size()
   {
      return m_entry_set.size();
   }

   bool has(const T & element)
   {
       auto entry_ptr = std::make_unique<Entry>(element, m_entry_vector.size());
      return m_entry_set.find(entry_ptr) != m_entry_set.end();
   }

   // Return the number of elements removed
   int erase(const T & element)
   {
       auto entry_ptr = std::make_unique<Entry>(element, m_entry_vector.size());
       auto it = m_entry_set.find(entry_ptr);
       if (it == m_entry_set.end())
          return 0;
       auto swap_with = it->get()->index_in_vector;
       if (swap_with < m_entry_vector.size() - 1) {
           m_entry_vector.back()->index_in_vector = swap_with;
           m_entry_vector[swap_with] = m_entry_vector.back();
       }
       m_entry_set.erase(it);
       m_entry_vector.pop_back();
       return 1;
   }
   template <typename RandomGenerator>
   const T & random_element(RandomGenerator & r)
   {
       std::uniform_int_distribution<> dis(0, m_entry_vector.size() - 1);
       return m_entry_vector[dis(r)]->data;

   }

private:
   std::unordered_set<std::unique_ptr<Entry>, PtrEntryHash, PtrEntryEqual> 
        m_entry_set;
   std::vector<Entry*> m_entry_vector;
};