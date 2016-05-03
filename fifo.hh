/**
 * @file
 * Declaration of a FIFO tag store.
 * The FIFO tags guarantee that the First-In Frist-Out way in
 * a set will always be evicted.
 */

#ifndef __MEM_CACHE_TAGS_FIFO_HH__
#define __MEM_CACHE_TAGS_FIFO_HH__

#include "mem/cache/tags/base_set_assoc.hh"
#include "params/fifo.hh"

class FIFO : public BaseSetAssoc
{
  public:
    /** Convenience typedef. */
    typedef FIFOParams Params;

    /**
     * Construct and initialize this tag store.
     */
    FIFO(const Params *p);

    /**
     * Destructor
     */
    ~FIFO() {}

    CacheBlk* accessBlock(Addr addr, bool is_secure, Cycles &lat,
                         int context_src);
    CacheBlk* findVictim(Addr addr);
    void insertBlock(PacketPtr pkt, BlkType *blk);
    void invalidate(CacheBlk *blk);
};

#endif // __MEM_CACHE_TAGS_FIFO_HH__
