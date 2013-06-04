<div class="comp_result">
  <?php if(!$status): ?>
    <h3><?php print t('No validation have been passed. Please update the node to see the compliance validation result.'); ?></h3>
  <?php else : ?>
    <div class="vid"><strong><em><?php if($revision) print $revision; ?><br> </em> <?php print t('Revision ID:'); ?></strong>  <?php print $vid; ?></div>
    <h2><?php print t('Status:'); ?> <strong><?php print $status; ?></strong></h2>
    <h3><?php print t('Errors:'); ?></h3> <?php print $numOfErrors; ?>
    <h3><?php print t('Likely Problems:'); ?></h3> <?php print $numOfLikelyProbs; ?>
    <h3><?php print t('Potential Problems:'); ?></h3> <?php print $numOfPotProbs; ?>
    <h3><?php print t('Guideline:'); ?></h3> <?php print $guideline; ?>
    <?php if($problems): ?>
      <h3><?php print t('Problems:'); ?></h3>
      <ul>
      <?php foreach ($problems as $problem): ?>
        <li>
          <p>
            <span><strong><?php print t('Type:'); ?></strong> <?php print $problem->result_type;?></span><br> 
            <strong><?php print t('Line:'); ?></strong> <?php print $problem->line_number; ?> <?php if (isset($problem->string)): ?>(<?php print $problem->string; ?>)<?php endif; ?><br>
            <strong><?php print t('Message:'); ?></strong> <?php print $problem->errorMsg; ?>    
          </p>
        </li>
      <?php endforeach; ?>
        </ul>
    <?php endif; ?>
  <?php endif; ?>
</div>
