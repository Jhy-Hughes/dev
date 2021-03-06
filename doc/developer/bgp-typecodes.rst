BGP-4[+] UPDATE Attribute Preprocessor Constants
================================================

This is a list of preprocessor constants that map to BGP attributes defined by
various BGP RFCs. In the code these are defined as BGP_ATTR_<ATTR>.

+-------+------------------+------------------------------------------+
| Value | Attribute        | References                               |
+=======+==================+==========================================+
| 1     | ORIGIN           | [RFC 4271]                               |
| 2     | AS_PATH          | [RFC 4271]                               |
| 3     | NEXT_HOP         | [RFC 4271]                               |
| 4     | MULTI_EXIT_DISC  | [RFC 4271]                               |
| 5     | LOCAL_PREF       | [RFC 4271]                               |
| 6     | ATOMIC_AGGREGATE | [RFC 4271]                               |
| 7     | AGGREGATOR       | [RFC 4271]                               |
| 8     | COMMUNITIES      | [RFC 1997]                               |
| 9     | ORIGINATOR_ID    | [RFC 4456]                               |
| 10    | CLUSTER_LIST     | [RFC 4456]                               |
| 14    | MP_REACH_NLRI    | [RFC 4760]                               |
| 15    | MP_UNREACH_NLRI  | [RFC 4760]                               |
| 16    | EXT_COMMUNITIES  | [RFC 4360]                               |
| 17    | AS4_PATH         | [RFC 4893]                               |
| 18    | AS4_AGGREGATOR   | [RFC 4893]                               |
+-------+------------------+------------------------------------------+
