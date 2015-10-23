#ifndef __ECONCURRENT_SET_H__
#define __ECONCURRENT_SET_H__

#include "EConcurrentIterator.hh"

namespace efc {

/**
 * A collection that contains no duplicate elements.  More formally, sets
 * contain no pair of elements <code>e1</code> and <code>e2</code> such that
 * <code>e1.equals(e2)</code>, and at most one null element.  As implied by
 * its name, this interface models the mathematical <i>set</i> abstraction.
 *
 * <p>The <tt>Set</tt> interface places additional stipulations, beyond those
 * inherited from the <tt>Collection</tt> interface, on the contracts of all
 * constructors and on the contracts of the <tt>add</tt>, <tt>equals</tt> and
 * <tt>hashCode</tt> methods.  Declarations for other inherited methods are
 * also included here for convenience.  (The specifications accompanying these
 * declarations have been tailored to the <tt>Set</tt> interface, but they do
 * not contain any additional stipulations.)
 *
 * <p>The additional stipulation on constructors is, not surprisingly,
 * that all constructors must create a set that contains no duplicate elements
 * (as defined above).
 *
 * <p>Note: Great care must be exercised if mutable objects are used as set
 * elements.  The behavior of a set is not specified if the value of an object
 * is changed in a manner that affects <tt>equals</tt> comparisons while the
 * object is an element in the set.  A special case of this prohibition is
 * that it is not permissible for a set to contain itself as an element.
 *
 * <p>Some set implementations have restrictions on the elements that
 * they may contain.  For example, some implementations prohibit null elements,
 * and some have restrictions on the types of their elements.  Attempting to
 * add an ineligible element throws an unchecked exception, typically
 * <tt>NullPointerException</tt> or <tt>ClassCastException</tt>.  Attempting
 * to query the presence of an ineligible element may throw an exception,
 * or it may simply return false; some implementations will exhibit the former
 * behavior and some will exhibit the latter.  More generally, attempting an
 * operation on an ineligible element whose completion would not result in
 * the insertion of an ineligible element into the set may throw an
 * exception or it may succeed, at the option of the implementation.
 * Such exceptions are marked as "optional" in the specification for this
 * interface.
 *
 * <p>This interface is a member of the
 * <a href="{@docRoot}/../technotes/guides/collections/index.html">
 * Java Collections Framework</a>.
 *
 * @param <E> the type of elements maintained by this set
 *
 * @author  Josh Bloch
 * @author  Neal Gafter
 * @version 1.39, 04/21/06
 * @see Collection
 * @see List
 * @see SortedSet
 * @see HashSet
 * @see TreeSet
 * @see AbstractSet
 * @see Collections#singleton(java.lang.Object)
 * @see Collections#EMPTY_SET
 * @since 1.2
 */

template<typename E>
interface EConcurrentSet : virtual public EObject
{
	virtual ~EConcurrentSet(){}
	
    // Query Operations

    /**
     * Returns the number of elements in this set (its cardinality).  If this
     * set contains more than <tt>Integer.MAX_VALUE</tt> elements, returns
     * <tt>Integer.MAX_VALUE</tt>.
     *
     * @return the number of elements in this set (its cardinality)
     */
    virtual int size() = 0;

    /**
     * Returns <tt>true</tt> if this set contains no elements.
     *
     * @return <tt>true</tt> if this set contains no elements
     */
    virtual boolean isEmpty() = 0;

    /**
     * Returns <tt>true</tt> if this set contains the specified element.
     * More formally, returns <tt>true</tt> if and only if this set
     * contains an element <tt>e</tt> such that
     * <tt>(o==null&nbsp;?&nbsp;e==null&nbsp;:&nbsp;o.equals(e))</tt>.
     *
     * @param o element whose presence in this set is to be tested
     * @return <tt>true</tt> if this set contains the specified element
     * @throws ClassCastException if the type of the specified element
     *         is incompatible with this set (optional)
     * @throws NullPointerException if the specified element is null and this
     *         set does not permit null elements (optional)
     */
    virtual boolean contains(E* o) = 0;

    /**
     * Returns an iterator over the elements in this set.  The elements are
     * returned in no particular order (unless this set is an instance of some
     * class that provides a guarantee).
     *
     * @return an iterator over the elements in this set
     */
    virtual sp<EConcurrentIterator<E> > iterator() = 0;


    // Modification Operations
    /**
	 * Adds the specified element to this set if it is not already present
	 * (optional operation).  More formally, adds the specified element
	 * <tt>e</tt> to this set if the set contains no element <tt>e2</tt>
	 * such that
	 * <tt>(e==null&nbsp;?&nbsp;e2==null&nbsp;:&nbsp;e.equals(e2))</tt>.
	 * If this set already contains the element, the call leaves the set
	 * unchanged and returns <tt>false</tt>.  In combination with the
	 * restriction on constructors, this ensures that sets never contain
	 * duplicate elements.
	 *
	 * <p>The stipulation above does not imply that sets must accept all
	 * elements; sets may refuse to add any particular element, including
	 * <tt>null</tt>, and throw an exception, as described in the
	 * specification for {@link Collection#add Collection.add}.
	 * Individual set implementations should clearly document any
	 * restrictions on the elements that they may contain.
	 *
	 * @param e element to be added to this set
	 * @return <tt>true</tt> if this set did not already contain the specified
	 *         element
	 * @throws UnsupportedOperationException if the <tt>add</tt> operation
	 *         is not supported by this set
	 * @throws ClassCastException if the class of the specified element
	 *         prevents it from being added to this set
	 * @throws NullPointerException if the specified element is null and this
	 *         set does not permit null elements
	 * @throws IllegalArgumentException if some property of the specified element
	 *         prevents it from being added to this set
	 */
	virtual boolean add(E* e) = 0;
	virtual boolean add(sp<E> e) = 0;

	/**
	 * Removes the specified element from this set if it is present
	 * (optional operation).  More formally, removes an element <tt>e</tt>
	 * such that
	 * <tt>(o==null&nbsp;?&nbsp;e==null&nbsp;:&nbsp;o.equals(e))</tt>, if
	 * this set contains such an element.  Returns <tt>true</tt> if this set
	 * contained the element (or equivalently, if this set changed as a
	 * result of the call).  (This set will not contain the element once the
	 * call returns.)
	 *
	 * @param o object to be removed from this set, if present
	 * @return <tt>true</tt> if this set contained the specified element
	 * @throws ClassCastException if the type of the specified element
	 *         is incompatible with this set (optional)
	 * @throws NullPointerException if the specified element is null and this
	 *         set does not permit null elements (optional)
	 * @throws UnsupportedOperationException if the <tt>remove</tt> operation
	 *         is not supported by this set
	 */
	virtual boolean remove(E* o) = 0;


	// Bulk Operations

	/**
	 * Removes all of the elements from this set (optional operation).
	 * The set will be empty after this call returns.
	 *
	 * @throws UnsupportedOperationException if the <tt>clear</tt> method
	 *         is not supported by this set
	 */
	virtual void clear() = 0;
};

} /* namespace efc */
#endif //!__ECONCURRENT_SET_H__
