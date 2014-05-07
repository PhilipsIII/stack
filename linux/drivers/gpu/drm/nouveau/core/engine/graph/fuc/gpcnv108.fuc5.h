uint32_t nv108_grgpc_data[] = {
/* 0x0000: gpc_mmio_list_head */
	0x0000006c,
/* 0x0004: gpc_mmio_list_tail */
/* 0x0004: tpc_mmio_list_head */
	0x0000006c,
/* 0x0008: tpc_mmio_list_tail */
/* 0x0008: unk_mmio_list_head */
	0x0000006c,
/* 0x000c: unk_mmio_list_tail */
	0x0000006c,
/* 0x0010: gpc_id */
	0x00000000,
/* 0x0014: tpc_count */
	0x00000000,
/* 0x0018: tpc_mask */
	0x00000000,
/* 0x001c: unk_count */
	0x00000000,
/* 0x0020: unk_mask */
	0x00000000,
/* 0x0024: cmd_queue */
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
};

uint32_t nv108_grgpc_code[] = {
	0x03140ef5,
/* 0x0004: queue_put */
	0x9800d898,
	0x86f001d9,
	0xf489a408,
	0x020f0b1b,
	0x0002f87e,
/* 0x001a: queue_put_next */
	0x98c400f8,
	0x0384b607,
	0xb6008dbb,
	0x8eb50880,
	0x018fb500,
	0xf00190b6,
	0xd9b50f94,
/* 0x0037: queue_get */
	0xf400f801,
	0xd8980131,
	0x01d99800,
	0x0bf489a4,
	0x0789c421,
	0xbb0394b6,
	0x90b6009d,
	0x009e9808,
	0xb6019f98,
	0x84f00180,
	0x00d8b50f,
/* 0x0063: queue_get_done */
	0xf80132f4,
/* 0x0065: nv_rd32 */
	0xf0ecb200,
	0x00801fc9,
	0x0cf601ca,
/* 0x0073: nv_rd32_wait */
	0x8c04bd00,
	0xcf01ca00,
	0xccc800cc,
	0xf61bf41f,
	0xec7e060a,
	0x008f0000,
	0xffcf01cb,
/* 0x008f: nv_wr32 */
	0x8000f800,
	0xf601cc00,
	0x04bd000f,
	0xc9f0ecb2,
	0x1ec9f01f,
	0x01ca0080,
	0xbd000cf6,
/* 0x00a9: nv_wr32_wait */
	0xca008c04,
	0x00cccf01,
	0xf41fccc8,
	0x00f8f61b,
/* 0x00b8: wait_donez */
	0x99f094bd,
	0x37008000,
	0x0009f602,
	0x008004bd,
	0x0af60206,
/* 0x00cf: wait_donez_ne */
	0x8804bd00,
	0xcf010000,
	0x8aff0088,
	0xf61bf488,
	0x99f094bd,
	0x17008000,
	0x0009f602,
	0x00f804bd,
/* 0x00ec: wait_doneo */
	0x99f094bd,
	0x37008000,
	0x0009f602,
	0x008004bd,
	0x0af60206,
/* 0x0103: wait_doneo_e */
	0x8804bd00,
	0xcf010000,
	0x8aff0088,
	0xf60bf488,
	0x99f094bd,
	0x17008000,
	0x0009f602,
	0x00f804bd,
/* 0x0120: mmctx_size */
/* 0x0122: nv_mmctx_size_loop */
	0xe89894bd,
	0x1a85b600,
	0xb60180b6,
	0x98bb0284,
	0x04e0b600,
	0x1bf4efa4,
	0xf89fb2ec,
/* 0x013d: mmctx_xfer */
	0xf094bd00,
	0x00800199,
	0x09f60237,
	0xbd04bd00,
	0x05bbfd94,
	0x800f0bf4,
	0xf601c400,
	0x04bd000b,
/* 0x015f: mmctx_base_disabled */
	0xfd0099f0,
	0x0bf405ee,
	0xc6008018,
	0x000ef601,
	0x008004bd,
	0x0ff601c7,
	0xf004bd00,
/* 0x017a: mmctx_multi_disabled */
	0xabc80199,
	0x10b4b600,
	0xc80cb9f0,
	0xe4b601ae,
	0x05befd11,
	0x01c50080,
	0xbd000bf6,
/* 0x0195: mmctx_exec_loop */
/* 0x0195: mmctx_wait_free */
	0xc5008e04,
	0x00eecf01,
	0xf41fe4f0,
	0xce98f60b,
	0x05e9fd00,
	0x01c80080,
	0xbd000ef6,
	0x04c0b604,
	0x1bf4cda4,
	0x02abc8df,
/* 0x01bf: mmctx_fini_wait */
	0x8b1c1bf4,
	0xcf01c500,
	0xb4f000bb,
	0x10b4b01f,
	0x0af31bf4,
	0x00b87e02,
	0x250ef400,
/* 0x01d8: mmctx_stop */
	0xb600abc8,
	0xb9f010b4,
	0x12b9f00c,
	0x01c50080,
	0xbd000bf6,
/* 0x01ed: mmctx_stop_wait */
	0xc5008b04,
	0x00bbcf01,
	0xf412bbc8,
/* 0x01fa: mmctx_done */
	0x94bdf61b,
	0x800199f0,
	0xf6021700,
	0x04bd0009,
/* 0x020a: strand_wait */
	0xa0f900f8,
	0xb87e020a,
	0xa0fc0000,
/* 0x0216: strand_pre */
	0x0c0900f8,
	0x024afc80,
	0xbd0009f6,
	0x020a7e04,
/* 0x0227: strand_post */
	0x0900f800,
	0x4afc800d,
	0x0009f602,
	0x0a7e04bd,
	0x00f80002,
/* 0x0238: strand_set */
	0xfc800f0c,
	0x0cf6024f,
	0x0c04bd00,
	0x4afc800b,
	0x000cf602,
	0xfc8004bd,
	0x0ef6024f,
	0x0c04bd00,
	0x4afc800a,
	0x000cf602,
	0x0a7e04bd,
	0x00f80002,
/* 0x0268: strand_ctx_init */
	0x99f094bd,
	0x37008003,
	0x0009f602,
	0x167e04bd,
	0x030e0002,
	0x0002387e,
	0xfc80c4bd,
	0x0cf60247,
	0x0c04bd00,
	0x4afc8001,
	0x000cf602,
	0x0a7e04bd,
	0x0c920002,
	0x46fc8001,
	0x000cf602,
	0x020c04bd,
	0x024afc80,
	0xbd000cf6,
	0x020a7e04,
	0x02277e00,
	0x42008800,
	0x20008902,
	0x0099cf02,
/* 0x02c7: ctx_init_strand_loop */
	0xf608fe95,
	0x8ef6008e,
	0x808acf40,
	0xb606a5b6,
	0xeabb01a0,
	0x0480b600,
	0xf40192b6,
	0xe4b6e81b,
	0xf2efbc08,
	0x99f094bd,
	0x17008003,
	0x0009f602,
	0x00f804bd,
/* 0x02f8: error */
	0xffb2e0f9,
	0x4098148e,
	0x00008f7e,
	0xffb2010f,
	0x409c1c8e,
	0x00008f7e,
	0x00f8e0fc,
/* 0x0314: init */
	0x04fe04bd,
	0x40020200,
	0x02f61200,
	0x4104bd00,
	0x10fe0465,
	0x07004000,
	0xbd0000f6,
	0x40040204,
	0x02f60400,
	0xf404bd00,
	0x00821031,
	0x22cf0182,
	0xf0010300,
	0x32bb1f24,
	0x0132b604,
	0xb50502b5,
	0x00820603,
	0x22cf0186,
	0x0402b500,
	0x500c308e,
	0x34bd24bd,
/* 0x036a: init_unk_loop */
	0x657e44bd,
	0xf6b00000,
	0x0e0bf400,
	0xf2bb010f,
	0x054ffd04,
/* 0x037f: init_unk_next */
	0xb60130b6,
	0xe0b60120,
	0x0126b004,
/* 0x038b: init_unk_done */
	0xb5e21bf4,
	0x04b50703,
	0x01008208,
	0x0022cf02,
	0x259534bd,
	0xc0008008,
	0x0005f601,
	0x008004bd,
	0x05f601c1,
	0x9804bd00,
	0x0f98000e,
	0x01207e01,
	0x002fbb00,
	0x98003fbb,
	0x0f98010e,
	0x01207e02,
	0x050e9800,
	0xbb00effd,
	0x3ebb002e,
	0x020e9800,
	0x7e030f98,
	0x98000120,
	0xeffd070e,
	0x002ebb00,
	0xb6003ebb,
	0x00800235,
	0x03f601d3,
	0xb604bd00,
	0x35b60825,
	0x0120b606,
	0xb60130b6,
	0x34b60824,
	0x7e2fb208,
	0xbb000268,
	0x0080003f,
	0x03f60201,
	0xbd04bd00,
	0x1f29f024,
	0x02300080,
	0xbd0002f6,
/* 0x0429: main */
	0x0031f404,
	0x0d0028f4,
	0x00377e24,
	0xf401f400,
	0xf404e4b0,
	0x81fe1d18,
	0xbd060201,
	0x0412fd20,
	0xfd01e4b6,
	0x18fe051e,
	0x04fc7e00,
	0xd40ef400,
/* 0x0458: main_not_ctx_xfer */
	0xf010ef94,
	0xf87e01f5,
	0x0ef40002,
/* 0x0465: ih */
	0xfe80f9c7,
	0x80f90188,
	0xa0f990f9,
	0xd0f9b0f9,
	0xf0f9e0f9,
	0x004a04bd,
	0x00aacf02,
	0xf404abc4,
	0x240d1f0b,
	0xcf1a004e,
	0x004f00ee,
	0x00ffcf19,
	0x0000047e,
	0x0040010e,
	0x000ef61d,
/* 0x04a2: ih_no_fifo */
	0x004004bd,
	0x000af601,
	0xf0fc04bd,
	0xd0fce0fc,
	0xa0fcb0fc,
	0x80fc90fc,
	0xfc0088fe,
	0x0032f480,
/* 0x04c2: hub_barrier_done */
	0x010f01f8,
	0xbb040e98,
	0xffb204fe,
	0x4094188e,
	0x00008f7e,
/* 0x04d6: ctx_redswitch */
	0x200f00f8,
	0x01850080,
	0xbd000ff6,
/* 0x04e3: ctx_redswitch_delay */
	0xb6080e04,
	0x1bf401e2,
	0x00f5f1fd,
	0x00f5f108,
	0x85008002,
	0x000ff601,
	0x00f804bd,
/* 0x04fc: ctx_xfer */
	0x02810080,
	0xbd000ff6,
	0x0711f404,
	0x0004d67e,
/* 0x050c: ctx_xfer_not_load */
	0x0002167e,
	0xfc8024bd,
	0x02f60247,
	0xf004bd00,
	0x20b6012c,
	0x4afc8003,
	0x0002f602,
	0xacf004bd,
	0x02a5f001,
	0x5000008b,
	0xb6040c98,
	0xbcbb0fc4,
	0x000c9800,
	0x0e010d98,
	0x013d7e00,
	0x01acf000,
	0x5040008b,
	0xb6040c98,
	0xbcbb0fc4,
	0x010c9800,
	0x98020d98,
	0x004e060f,
	0x013d7e08,
	0x01acf000,
	0x8b04a5f0,
	0x98503000,
	0xc4b6040c,
	0x00bcbb0f,
	0x98020c98,
	0x0f98030d,
	0x02004e08,
	0x00013d7e,
	0x00020a7e,
	0xf40601f4,
/* 0x0596: ctx_xfer_post */
	0x277e0712,
/* 0x059a: ctx_xfer_done */
	0xc27e0002,
	0x00f80004,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
};
