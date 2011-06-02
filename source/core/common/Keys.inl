/**
 * @file sf1r/driver/Keys.inl
 * @date Created <2011-06-02 11:09:24>
 *
 * This file is generated by generators/driver_keys.rb by collecting keys
 * from source code. Do not edit this file directly.
 */

#define SF1_DRIVER_KEYS \
(DOCID)\
(ITEMID)\
(USERID)\
(_categories)\
(_custom_rank)\
(_duplicated_document_count)\
(_id)\
(_image_id)\
(_rank)\
(_similar_document_count)\
(analyzer)\
(analyzer_result)\
(apply_la)\
(category_id)\
(cid)\
(cname)\
(collection)\
(condition)\
(conditions)\
(content)\
(count)\
(counter)\
(custom_rank)\
(doccount)\
(docid)\
(docid_list)\
(document_count)\
(document_support_count)\
(duplicate_with)\
(duration)\
(elapsed_time)\
(exclude_items)\
(expression)\
(faceted)\
(freq)\
(func)\
(group)\
(group_label)\
(groupby)\
(highlight)\
(hit_docs_num)\
(id)\
(in)\
(include_items)\
(index)\
(input_items)\
(items)\
(keywords)\
(label)\
(labels)\
(last_modified)\
(left_time)\
(level)\
(limit)\
(log_keywords)\
(manmade)\
(max_count)\
(message)\
(meta)\
(min_freq)\
(mining)\
(name)\
(name_entity)\
(name_entity_item)\
(name_entity_list)\
(name_entity_type)\
(offset)\
(operator_)\
(order)\
(order_id)\
(page_count)\
(page_start)\
(params)\
(popular)\
(popular_queries)\
(prefix)\
(price)\
(progress)\
(property)\
(quantity)\
(query)\
(ranking_model)\
(realtime)\
(realtime_queries)\
(rec_type)\
(recent)\
(refined_query)\
(related_queries)\
(remote_ip)\
(remove_duplicated_result)\
(resource)\
(resources)\
(search)\
(search_session)\
(seconds)\
(select)\
(session_id)\
(sim_list)\
(similar_to)\
(similar_to_image)\
(snippet)\
(sort)\
(source)\
(status)\
(sub_labels)\
(summary)\
(summary_property_alias)\
(summary_sentence_count)\
(system_events)\
(taxonomy)\
(taxonomy_label)\
(timestamp)\
(top_k_count)\
(total_count)\
(type)\
(use_original_keyword)\
(use_synonym_extension)\
(user_queries)\
(value)\
(weight)


/* LOCATIONS

DOCID
  process/controllers/DocumentsController.cpp:470
  process/controllers/DocumentsController.cpp:537
  process/controllers/DocumentsController.cpp:585
  process/controllers/DocumentsGetHandler.cpp:273
  process/controllers/DocumentsGetHandler.cpp:275
  process/controllers/DocumentsGetHandler.cpp:328
  process/controllers/DocumentsGetHandler.cpp:353

ITEMID
  process/controllers/RecommendController.cpp:98
  process/controllers/RecommendController.cpp:144
  process/controllers/RecommendController.cpp:153
  process/controllers/RecommendController.cpp:188
  process/controllers/RecommendController.cpp:471
  process/controllers/RecommendController.cpp:522
  process/controllers/RecommendController.cpp:566
  process/controllers/RecommendController.cpp:568
  process/controllers/RecommendController.cpp:618
  process/controllers/RecommendController.cpp:621
  process/controllers/RecommendController.cpp:627
  process/controllers/RecommendController.cpp:680
  process/controllers/RecommendController.cpp:683
  process/controllers/RecommendController.cpp:754
  process/controllers/RecommendController.cpp:757
  process/controllers/RecommendController.cpp:949
  process/controllers/RecommendController.cpp:1064

USERID
  process/parsers/SearchParser.cpp:94
  process/controllers/RecommendController.cpp:64
  process/controllers/RecommendController.cpp:262
  process/controllers/RecommendController.cpp:312
  process/controllers/RecommendController.cpp:356
  process/controllers/RecommendController.cpp:358
  process/controllers/RecommendController.cpp:407
  process/controllers/RecommendController.cpp:410
  process/controllers/RecommendController.cpp:416
  process/controllers/RecommendController.cpp:679
  process/controllers/RecommendController.cpp:682
  process/controllers/RecommendController.cpp:737
  process/controllers/RecommendController.cpp:739
  process/controllers/RecommendController.cpp:875

_categories
  process/renderers/DocumentsRenderer.cpp:157

_custom_rank
  process/renderers/DocumentsRenderer.cpp:100

_duplicated_document_count
  process/renderers/DocumentsRenderer.cpp:138

_id
  process/renderers/DocumentsRenderer.cpp:39
  process/renderers/DocumentsRenderer.cpp:94
  process/controllers/FacetedController.cpp:393
  process/controllers/DocumentsGetHandler.cpp:268
  process/controllers/DocumentsGetHandler.cpp:270
  process/controllers/DocumentsGetHandler.cpp:328
  process/controllers/DocumentsGetHandler.cpp:345

_image_id
  process/renderers/DocumentsRenderer.cpp:151
  process/controllers/DocumentsGetHandler.cpp:192

_rank
  process/renderers/DocumentsRenderer.cpp:95

_similar_document_count
  process/renderers/DocumentsRenderer.cpp:145

analyzer
  process/parsers/SearchParser.cpp:203

analyzer_result
  process/controllers/DocumentsSearchHandler.cpp:514
  process/controllers/DocumentsSearchHandler.cpp:532

apply_la
  process/parsers/SearchParser.cpp:204

category_id
  process/controllers/FacetedController.cpp:413
  process/controllers/FacetedController.cpp:415

cid
  process/controllers/FacetedController.cpp:395

cname
  process/controllers/FacetedController.cpp:396

collection
  process/controllers/LogAnalysisController.cpp:254
  process/controllers/LogAnalysisController.cpp:270
  process/controllers/LogAnalysisController.cpp:327
  process/controllers/CommandsController.cpp:25
  process/controllers/KeywordsController.cpp:64
  process/controllers/DocumentsSearchHandler.cpp:78
  process/controllers/StatusController.cpp:44
  process/controllers/DocumentsController.cpp:606
  process/controllers/Sf1Controller.cpp:37
  process/controllers/QueryCorrectionController.cpp:28

condition
  process/controllers/RecommendController.cpp:165

conditions
  process/controllers/LogAnalysisController.cpp:69
  process/controllers/LogAnalysisController.cpp:71
  process/controllers/DocumentsSearchHandler.cpp:386
  process/controllers/DocumentsGetHandler.cpp:316

content
  process/controllers/LogAnalysisController.cpp:181
  process/controllers/FacetedController.cpp:49
  process/controllers/FacetedController.cpp:103

count
  process/controllers/LogAnalysisController.cpp:261

counter
  process/controllers/StatusController.cpp:73

custom_rank
  process/controllers/DocumentsSearchHandler.cpp:390
  process/controllers/DocumentsSearchHandler.cpp:393

doccount
  process/controllers/FacetedController.cpp:160
  process/controllers/FacetedController.cpp:277

docid
  process/controllers/FacetedController.cpp:394

docid_list
  process/controllers/FacetedController.cpp:428

document_count
  process/renderers/DocumentsRenderer.cpp:237
  process/renderers/DocumentsRenderer.cpp:301
  process/renderers/DocumentsRenderer.cpp:350
  process/renderers/DocumentsRenderer.cpp:356
  process/controllers/CommandsController.cpp:64
  process/controllers/StatusController.cpp:55
  process/controllers/StatusController.cpp:71

document_support_count
  process/renderers/DocumentsRenderer.cpp:269

duplicate_with
  process/controllers/DocumentsGetHandler.cpp:101

duration
  process/controllers/LogAnalysisController.cpp:259
  process/controllers/LogAnalysisController.cpp:275
  process/controllers/LogAnalysisController.cpp:347
  process/controllers/LogAnalysisController.cpp:351
  process/controllers/LogAnalysisController.cpp:359

elapsed_time
  process/controllers/StatusController.cpp:67

exclude_items
  process/controllers/RecommendController.cpp:864

expression
  process/parsers/CustomRankingParser.cpp:91
  process/parsers/CustomRankingParser.cpp:92

faceted
  process/controllers/DocumentsSearchHandler.cpp:723

freq
  process/controllers/RecommendController.cpp:1056

func
  core/common/parsers/SelectFieldParser.cpp:32

group
  process/controllers/DocumentsSearchHandler.cpp:406
  process/controllers/DocumentsSearchHandler.cpp:728

group_label
  process/parsers/SearchParser.cpp:102
  process/parsers/SearchParser.cpp:122

groupby
  process/controllers/LogAnalysisController.cpp:105
  process/controllers/LogAnalysisController.cpp:107

highlight
  process/parsers/SelectParser.cpp:119

hit_docs_num
  process/controllers/LogAnalysisController.cpp:255
  process/controllers/LogAnalysisController.cpp:271
  process/controllers/LogAnalysisController.cpp:338

id
  process/renderers/DocumentsRenderer.cpp:300
  process/controllers/TopicController.cpp:71
  process/controllers/DocumentsController.cpp:497
  process/controllers/FacetedController.cpp:159
  process/controllers/FacetedController.cpp:276

in
  process/parsers/SearchParser.cpp:152

include_items
  process/controllers/RecommendController.cpp:863

index
  process/controllers/StatusController.cpp:52

input_items
  process/controllers/RecommendController.cpp:862

items
  process/controllers/RecommendController.cpp:742
  process/controllers/RecommendController.cpp:1058

keywords
  process/parsers/SearchParser.cpp:87
  process/controllers/AutoFillController.cpp:102
  process/controllers/QueryCorrectionController.cpp:29

label
  process/renderers/DocumentsRenderer.cpp:236
  process/renderers/DocumentsRenderer.cpp:299
  process/renderers/DocumentsRenderer.cpp:355

labels
  process/renderers/DocumentsRenderer.cpp:226
  process/renderers/DocumentsRenderer.cpp:287
  process/renderers/DocumentsRenderer.cpp:351

last_modified
  process/controllers/StatusController.cpp:54
  process/controllers/StatusController.cpp:72
  process/controllers/StatusController.cpp:79
  process/controllers/StatusController.cpp:86

left_time
  process/controllers/StatusController.cpp:68

level
  process/controllers/LogAnalysisController.cpp:179
  process/controllers/FacetedController.cpp:157
  process/controllers/FacetedController.cpp:274

limit
  core/common/parsers/PageInfoParser.cpp:20
  core/common/parsers/PageInfoParser.cpp:22
  process/controllers/AutoFillController.cpp:77
  process/controllers/LogAnalysisController.cpp:165
  process/controllers/LogAnalysisController.cpp:208
  process/controllers/KeywordsController.cpp:65
  process/controllers/DocumentsController.cpp:596
  process/controllers/DocumentsController.cpp:598

log_keywords
  process/parsers/SearchParser.cpp:149

manmade
  process/controllers/FacetedController.cpp:387

max_count
  process/controllers/RecommendController.cpp:848
  process/controllers/RecommendController.cpp:1021

message
  process/controllers/TestController.cpp:28
  process/controllers/TestController.cpp:28

meta
  process/controllers/StatusController.cpp:69

min_freq
  process/controllers/RecommendController.cpp:1033

mining
  process/controllers/StatusController.cpp:77

name
  process/parsers/CustomRankingParser.cpp:126
  process/controllers/TopicController.cpp:61
  process/controllers/DocumentsController.cpp:500
  process/controllers/DocumentsController.cpp:568
  process/controllers/DocumentsController.cpp:576
  process/controllers/FacetedController.cpp:158
  process/controllers/FacetedController.cpp:275

name_entity
  process/controllers/DocumentsSearchHandler.cpp:718

name_entity_item
  process/parsers/SearchParser.cpp:99
  process/parsers/SearchParser.cpp:111
  process/renderers/DocumentsRenderer.cpp:268

name_entity_list
  process/renderers/DocumentsRenderer.cpp:260

name_entity_type
  process/parsers/SearchParser.cpp:100
  process/parsers/SearchParser.cpp:112

offset
  core/common/parsers/PageInfoParser.cpp:15
  core/common/parsers/PageInfoParser.cpp:17

operator_
  core/common/parsers/ConditionParser.cpp:68

order
  core/common/parsers/OrderParser.cpp:23

order_id
  process/controllers/RecommendController.cpp:740

page_count
  process/controllers/LogAnalysisController.cpp:257
  process/controllers/LogAnalysisController.cpp:273
  process/controllers/LogAnalysisController.cpp:340

page_start
  process/controllers/LogAnalysisController.cpp:256
  process/controllers/LogAnalysisController.cpp:272
  process/controllers/LogAnalysisController.cpp:339

params
  process/parsers/CustomRankingParser.cpp:80
  process/parsers/CustomRankingParser.cpp:81

popular
  process/controllers/KeywordsController.cpp:126
  process/controllers/KeywordsController.cpp:136
  process/controllers/KeywordsController.cpp:138

popular_queries
  process/controllers/DocumentsSearchHandler.cpp:703

prefix
  process/controllers/AutoFillController.cpp:76

price
  process/controllers/RecommendController.cpp:762

progress
  process/controllers/StatusController.cpp:66

property
  core/common/parsers/ConditionParser.cpp:43
  core/common/parsers/SelectFieldParser.cpp:30
  core/common/parsers/OrderParser.cpp:22
  process/parsers/SearchParser.cpp:132
  process/parsers/SearchParser.cpp:165
  process/parsers/GroupingParser.cpp:54
  process/parsers/SelectParser.cpp:118
  process/renderers/DocumentsRenderer.cpp:349
  process/controllers/RecommendController.cpp:178
  process/controllers/RecommendController.cpp:181

quantity
  process/controllers/RecommendController.cpp:761

query
  process/controllers/LogAnalysisController.cpp:253
  process/controllers/LogAnalysisController.cpp:269
  process/controllers/LogAnalysisController.cpp:326

ranking_model
  process/parsers/SearchParser.cpp:210
  process/parsers/SearchParser.cpp:212

realtime
  process/controllers/KeywordsController.cpp:127
  process/controllers/KeywordsController.cpp:163
  process/controllers/KeywordsController.cpp:165

realtime_queries
  process/controllers/DocumentsSearchHandler.cpp:708

rec_type
  process/controllers/RecommendController.cpp:845
  process/controllers/RecommendController.cpp:876

recent
  process/controllers/KeywordsController.cpp:97
  process/controllers/KeywordsController.cpp:99

refined_query
  process/controllers/DocumentsSearchHandler.cpp:741
  process/controllers/QueryCorrectionController.cpp:41

related_queries
  process/controllers/DocumentsSearchHandler.cpp:698

remote_ip
  process/controllers/DocumentsSearchHandler.cpp:77
  process/controllers/DocumentsGetHandler.cpp:40

remove_duplicated_result
  process/controllers/DocumentsSearchHandler.cpp:513

resource
  process/controllers/DocumentsController.cpp:341
  process/controllers/DocumentsController.cpp:385
  process/controllers/DocumentsController.cpp:426
  process/controllers/DocumentsController.cpp:469
  process/controllers/DocumentsController.cpp:536
  process/controllers/DocumentsController.cpp:585
  process/controllers/RecommendController.cpp:45
  process/controllers/RecommendController.cpp:124
  process/controllers/RecommendController.cpp:165
  process/controllers/RecommendController.cpp:265
  process/controllers/RecommendController.cpp:315
  process/controllers/RecommendController.cpp:358
  process/controllers/RecommendController.cpp:410
  process/controllers/RecommendController.cpp:415
  process/controllers/RecommendController.cpp:474
  process/controllers/RecommendController.cpp:525
  process/controllers/RecommendController.cpp:568
  process/controllers/RecommendController.cpp:621
  process/controllers/RecommendController.cpp:626
  process/controllers/RecommendController.cpp:682
  process/controllers/RecommendController.cpp:683
  process/controllers/RecommendController.cpp:739
  process/controllers/RecommendController.cpp:740
  process/controllers/RecommendController.cpp:742
  process/controllers/RecommendController.cpp:848
  process/controllers/RecommendController.cpp:875
  process/controllers/RecommendController.cpp:876
  process/controllers/RecommendController.cpp:1021
  process/controllers/RecommendController.cpp:1033

resources
  process/controllers/TopicController.cpp:54
  process/controllers/DocumentsSearchHandler.cpp:675
  process/controllers/DocumentsSearchHandler.cpp:686
  process/controllers/DocumentsController.cpp:492
  process/controllers/DocumentsController.cpp:561
  process/controllers/RecommendController.cpp:941
  process/controllers/RecommendController.cpp:1051
  process/controllers/FacetedController.cpp:147
  process/controllers/FacetedController.cpp:210
  process/controllers/FacetedController.cpp:264
  process/controllers/FacetedController.cpp:327
  process/controllers/DocumentsGetHandler.cpp:48
  process/controllers/DocumentsGetHandler.cpp:183
  process/controllers/DocumentsGetHandler.cpp:393
  process/controllers/DocumentsGetHandler.cpp:411
  process/controllers/DocumentsGetHandler.cpp:443

search
  process/controllers/DocumentsSearchHandler.cpp:382

search_session
  process/controllers/DocumentsGetHandler.cpp:227
  process/controllers/DocumentsGetHandler.cpp:230

seconds
  process/controllers/TestController.cpp:43

select
  process/controllers/LogAnalysisController.cpp:29
  process/controllers/LogAnalysisController.cpp:31
  process/controllers/KeywordsController.cpp:75
  process/controllers/KeywordsController.cpp:79
  process/controllers/DocumentsSearchHandler.cpp:378
  process/controllers/DocumentsGetHandler.cpp:208

session_id
  process/controllers/LogAnalysisController.cpp:258
  process/controllers/LogAnalysisController.cpp:274

sim_list
  process/controllers/DocumentsController.cpp:569

similar_to
  process/controllers/TopicController.cpp:68
  process/controllers/TopicController.cpp:70
  process/controllers/DocumentsGetHandler.cpp:59

similar_to_image
  process/controllers/DocumentsGetHandler.cpp:143

snippet
  process/parsers/SelectParser.cpp:131

sort
  process/controllers/LogAnalysisController.cpp:53
  process/controllers/LogAnalysisController.cpp:55
  process/controllers/DocumentsSearchHandler.cpp:398

source
  process/controllers/LogAnalysisController.cpp:180

status
  process/controllers/StatusController.cpp:53
  process/controllers/StatusController.cpp:62
  process/controllers/StatusController.cpp:78
  process/controllers/StatusController.cpp:84

sub_labels
  process/renderers/DocumentsRenderer.cpp:242
  process/renderers/DocumentsRenderer.cpp:312
  process/renderers/DocumentsRenderer.cpp:357

summary
  process/parsers/SelectParser.cpp:120

summary_property_alias
  process/parsers/SelectParser.cpp:128

summary_sentence_count
  process/parsers/SelectParser.cpp:124

system_events
  process/controllers/LogAnalysisController.cpp:174

taxonomy
  process/controllers/DocumentsSearchHandler.cpp:713

taxonomy_label
  process/parsers/SearchParser.cpp:97
  process/parsers/SearchParser.cpp:110

timestamp
  process/controllers/LogAnalysisController.cpp:182
  process/controllers/LogAnalysisController.cpp:260
  process/controllers/LogAnalysisController.cpp:276
  process/controllers/LogAnalysisController.cpp:368
  process/controllers/LogAnalysisController.cpp:372
  process/controllers/LogAnalysisController.cpp:380

top_k_count
  process/controllers/DocumentsSearchHandler.cpp:99
  process/controllers/DocumentsSearchHandler.cpp:197

total_count
  process/controllers/AutoFillController.cpp:99
  process/controllers/DocumentsSearchHandler.cpp:98
  process/controllers/DocumentsSearchHandler.cpp:196
  process/controllers/DocumentsGetHandler.cpp:48
  process/controllers/DocumentsGetHandler.cpp:90
  process/controllers/DocumentsGetHandler.cpp:131
  process/controllers/DocumentsGetHandler.cpp:197
  process/controllers/DocumentsGetHandler.cpp:443

type
  process/parsers/CustomRankingParser.cpp:139
  process/renderers/DocumentsRenderer.cpp:258

use_original_keyword
  process/parsers/SearchParser.cpp:205

use_synonym_extension
  process/parsers/SearchParser.cpp:206

user_queries
  process/controllers/LogAnalysisController.cpp:244
  process/controllers/LogAnalysisController.cpp:310
  process/controllers/LogAnalysisController.cpp:315
  process/controllers/LogAnalysisController.cpp:318

value
  core/common/parsers/ConditionParser.cpp:50
  core/common/parsers/ConditionParser.cpp:57
  core/common/parsers/ConditionParser.cpp:64
  process/parsers/SearchParser.cpp:133
  process/parsers/CustomRankingParser.cpp:140
  process/parsers/CustomRankingParser.cpp:147
  process/parsers/CustomRankingParser.cpp:152
  process/controllers/RecommendController.cpp:195

weight
  process/controllers/RecommendController.cpp:946

*/
